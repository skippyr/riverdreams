use super::error_treatment::print_error;
use std::
{
	process::exit,
	env::var
};

pub fn is_to_use_fallback_text() -> bool
{
	match var("RIVER_DREAMS_USE_FALLBACK_TEXT")
	{
		Ok(is_to_use_fallback_text) =>
		{ is_to_use_fallback_text == "1" }
		Err(_error) =>
		{ false }
	}
}

pub fn get_pwd() -> String
{
	match var("PWD")
	{
		Ok(pwd) =>
		{ pwd }
		Err(_error) =>
		{
			print_error(
				"could not get the value of the environment variable PWD.",
				"ensure that you are running it from an UNIX operating system.",
				1
			);
			exit(1);
		}
	}
}

pub fn get_home() -> String
{
	match var("HOME")
	{
		Ok(home) =>
		{ home }
		Err(_error) =>
		{
			print_error(
				"could not get the value of the environment variable HOME.",
				"ensure that you are running it from an UNIX operating system.",
				1
			);
			exit(1);
		}
	}
}

pub fn get_virtual_env() -> Option<String>
{
	match var("VIRTUAL_ENV")
	{
		Ok(virtual_env) =>
		{ Some(virtual_env) }
		Err(_error) =>
		{ None }
	}
}

