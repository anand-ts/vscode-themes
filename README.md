# Selecta Mea – VS Code Theme Pack

> _Latin: selecta mea — “my selections”._

![Thumbnail](./public/images/themes-dark.png)
![Thumbnail](./public/images/themes-light.png)

17 color themes bundled in one Visual Studio Code extension, with 11 dark themes and 6 light themes.

## Update (ver. 3.2.0)

- New "Coral Citrus (Dark)" theme
- Improved contrast for Coral Citrus's prominent status bar labels
- Added extension documentation, release notes, and Marketplace metadata

## Update (ver. 3.1.0)

- New "Blueberry" theme
- New "Void" theme
- New "Sepia Sharp Solarized" theme
- New "Dark Modern Pink" theme
- Removed "Desert Solarized" in favor of "Sepia Sharp"
- General theme polishes

## Code Snippets

### Bubblegum (Dark)
![Bubblegum Dark](./public/images/bubblegum-dark.png)

### Catppuccin Mocha Affogato
![Catppuccin Mocha Affogato](./public/images/catppuccin-mocha-affogato.png)

### ChatGPT Theme (Dark)
![ChatGPT Theme Dark](./public/images/chatgpt-theme-dark.png)

### Claude Theme (Dark)
![Claude Theme Dark](./public/images/claude-theme-dark.png)

### Darcula
![Darcula](./public/images/darcula.png)

### Iceberg Theme (Dark)
![Iceberg Theme Dark](./public/images/iceberg-theme-dark.png)

### Monokai Space Gray — Polished
![Monokai Space Gray](./public/images/monokai-space-gray.png)

### Bubblegum (Light)
![Bubblegum Light](./public/images/bubblegum-light.png)

### ChatGPT Theme (Light)
![ChatGPT Light](./public/images/chatgpt-theme-light.png)

### Claude Theme (Light)
![Claude Theme Light](./public/images/claude-theme-light.png)

### Iceberg Theme (Light)
![Iceberg Theme Light](./public/images/iceberg-theme-light.png)

### Light Modern (Plus)
![Light Modern Plus](./public/images/light-modern-plus.png)

## Themes

### Dark (11)

- Blueberry (Dark)
- Bubblegum (Dark)
- Catppuccin Mocha Affogato
- ChatGPT Theme (Dark)
- Claude Theme (Dark)
- Coral Citrus (Dark)
- Darcula
- Dark Modern Pink
- Iceberg Theme (Dark)
- Monokai Space Gray — Polished
- Void (Dark)

### Light (6)

- Bubblegum (Light)
- ChatGPT Theme (Light)
- Claude Theme (Light)
- Iceberg Theme (Light)
- Light Modern (Plus)
- Sepia Sharp Solarized

## Features

- High contrast and readability
- Semantic highlighting support
- Terminal styling included
- Git diff colors optimized

## Installation

Install [Selecta Mea Theme Pack from the VS Code Marketplace](https://marketplace.visualstudio.com/items?itemName=anand-ts.selecta-mea-themes), then run "Preferences: Color Theme" and choose a theme from the pack.

You can also install the packaged release manually:

1. Download [selecta-mea-themes-3.2.0.vsix](./selecta-mea-themes/selecta-mea-themes-3.2.0.vsix)
2. Open VS Code
3. Press `Cmd+Shift+P` or `Ctrl+Shift+P`
4. Type "Install from VSIX"
5. Select the downloaded file and reload
6. Run "Preferences: Color Theme" and choose a theme from the pack

## Distribution

Distributed as a VS Code theme extension with the identifier `anand-ts.selecta-mea-themes`. The VSIX includes all 17 themes.

## Packaging and publishing

Install the [VS Code extension CLI](https://code.visualstudio.com/api/working-with-extensions/publishing-extension), then run this command from `selecta-mea-themes/` with the local theme JSON files available:

```sh
vsce package --no-dependencies --githubBranch main
```

Marketplace publishing requires access to the `anand-ts` publisher. Configure authentication using the [official publishing guide](https://code.visualstudio.com/api/working-with-extensions/publishing-extension), then publish the packaged release from the same directory:

```sh
vsce publish --packagePath selecta-mea-themes-3.2.0.vsix
```

## License

MIT License

---

Version 3.2.0
