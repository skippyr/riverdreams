#!/usr/bin/env zsh

river_dreams::ignored_files() {
  local -r ignored_files_quantity=$(
    git status -s --ignored 2>/dev/null |
    grep "! " |
    wc -l
  )
  local -r ignored_files_symbol=$(
    test $(tput colors) -eq 8 &&
    echo "IGNORED" ||
    echo "󰮀"
  )

  if [[ ${ignored_files_quantity} -gt 0 ]]; then
    echo "%F{magenta}${ignored_files_symbol} %f${ignored_files_quantity}"
  fi
}
