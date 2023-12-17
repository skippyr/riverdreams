# river-dreams
A tribal-inspired ZSH theme for Linux.

![](preview.png)

It displays:

- Your local IPv4 address.
- Your disk usage.
- Your battery percentage.
- A calendar.
- A clock.
- A decorator for root user.
- A decorator for exit codes.

## Requirements
In order to build it, you will need:

- A C99 compiler, like `tcc`.
- The [Noto Sans](https://fonts.google.com/noto/specimen/Noto+Sans) font.
- A font patched by the [Nerd Fonts](https://www.nerdfonts.com/font-downloads)
  project (release `>= 3.0.0`).

## Installation
- Compile the file `river-dreams.c`.

```bash
mkdir -p ~/.local/bin/river-dreams
tcc -o ~/.local/bin/river-dreams river-dreams.c
```

- Set it as your prompt in your `~/.zshrc` file.

```zsh
setopt prompsubst
PROMPT='$(~/.local/bin/river-dreams)'
```

- Reopen ZSH.

## Copyright
See LICENSE for copyright and license details.
