package write

import (
	"embed"
	"io/fs"
	"io/ioutil"
	"os"
	"path/filepath"
)

//go:embed fs
var template embed.FS

func Write(name string) {
	err := fs.WalkDir(template, "fs", func(path string, d fs.DirEntry, err error) error {
		if err != nil {
			return err
		}
		relPath, err := filepath.Rel("fs", path)
		if err != nil {
			return err
		}
		outputPath := filepath.Join(name, relPath)
		if d.IsDir() {
			return os.MkdirAll(outputPath, os.ModePerm)
		}
		data, err := template.ReadFile(path)
		if err != nil {
			return err
		}
		return ioutil.WriteFile(outputPath, data, os.ModePerm)
	})
	if err != nil {
		panic(err)
	}
}
