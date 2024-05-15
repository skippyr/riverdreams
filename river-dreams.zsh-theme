setopt promptsubst;

export VIRTUAL_ENV_DISABLE_PROMPT=1;
_river_dreams_g_root=$(dirname ${0});

make -sC ${_river_dreams_g_root};

PROMPT='$(${_river_dreams_g_root}/build/bin/left-prompt ${ZVM_MODE})';
RPROMPT='$(${_river_dreams_g_root}/build/bin/right-prompt)';
