<h1>River Dreams</h1>
	<h2>Starting Point</h2>
		<p>A tribal inspired theme for the ZSH shell that includes a fallback text feature.</p>
		<p>When dealing with shells, a theme for it means the prompt that you see when typing commands and not necessary the colors.</p>
		<p>River Dreams takes minimal aesthetics and features into account to bring you a graceful experience when using a terminal emulator.</p>
		<p>In the preview, below, you can see a demo of River Dreams with its default look.</p>
		<img src="./images/preview.gif"/>
		<p>For those moments where you can not have access to a rich terminal and have to use bitmap fonts, River Dreams will still be there with you: it includes a fallback text feature that is automatically activated based in your terminal emulator's color support. Or you can manually activate it too.</p>
		<img src="./images/preview_fallback.gif"/>
	<h2>Aesthetics</h2>
		<p>River Dreams is heavily inspired by tribal patterns, which you will see throughout the whole set of symbols I have chosen for it.</p>
		<p>It is also inspired in the look of other popular ZSH and Fish themes:</p>
		<ul>
			<li><code>robbyrussel</code> from the <a href="https://github.com/ohmyzsh/ohmyzsh">OhMyZSH</a> framework.</li>
			<li><a href="https://github.com/romkatv/powerlevel10k">Powerlevel10k</a>.</li>
			<li><a href="https://github.com/spaceship-prompt/spaceship-prompt">Spaceship Prompt</a>.</li>
			<li>The default theme for the <a href="https://fishshell.com/">Fish shell</a>.</li>
		</ul>
		<p>So, you will probably find some similarities with those themes too.</p>
	<h2>Features</h2>
		<p>A ZSH theme can be divided in two parts: a prompt that will be on the left side of your screen: the left prompt, and another that will be in the right side: the right prompt. River Dreams works with the same architecture and that is what will be used as reference now.</p>
		<p>In its left prompt you will find:</p>
		<ul>
			<li>A separator that fits your terminal emulator's width to isolate the prompt from the output of your last commands.</li>
			<li>Your local IPV4 address.</li>
			<li>The in-use percentage of the disk partition mounted at <code>/</code>.</li>
			<li>A calendar that shows the name of the month abbreviated and the day.</li>
			<li>A clock that shows the hour and minute in 24 hours format.</li>
			<li>A hash decorator to show if you are root or not.</li>
			<li>The name of sourced virtual environments.</li>
			<li>Your current directory path abbreviated, shrinking the path of home and <code>git</code> repositories directories.</li>
			<li>A lock decorator if you are not the user owner of the current directory.</li>
			<li>The name of the branch if you are inside a <code>git</code> repository.</li>
		</ul>
		<p>In its right prompt, you will find:</p>
			<ul>
				<li>The quantity of executable files, hidden files and symbolic links in your current directory.</li>
				<li>The quantity of jobs running in the background for the current shell session.</li>
			</ul>
	<h2>Speed</h2>
		<p>I knew that you would ask. River Dreams is built using Rust, a modern compiled programming language, that will take the best effort to make it fast for your daily usage.</p>
	<h2>Installation And Usage</h2>
		<p>Want to try out River Dreams? Awesome. In this section, let's talk about how to configure ZSH for your terminal emulator and how to install the River Dreams theme on top of it.</p>
		<p>Installation instructions are intended for Linux and MacOS operating systems, but if you are using Windows, you can still follow along by running a Linux virtual machine inside of WSL (Windows Subsystem for Linux).</p>
		<h3>Configuring the ZSH shell</h3>
			<p>A shell is the program that has the function to receive and interpret the commands that you type, and pass them to the system's kernel to execute.</p>
			<p>There are many shells applications, being ZSH one of them. One of its key features is that it is easier to customize, while maintaining compatibility with the syntax of the Bash shell.</p>
			<p>In MacOS, the ZSH shell is the default one since Catalina release. However, on Linux, Bash is the default one. For that reason, in this section you will learn how to configure ZSH as the default shell for your current user if it is not already.</p>
			<p>First, you will need to install it. In Linux, you can refer to your distribution's package manager to do so. For example, if you are using Ubuntu or based distributions of it, you can use the following command to install ZSH (sudo priveleges are required to do it):</p>
			<pre><code>sudo apt install -y zsh</code></pre>
			<p>After installing ZSH, it is time to make it the default one.</p>
			<p>Your user has a default shell set in the system. To change it to use ZSH, you can use the following command (your password will be required to do it):</p>
			<pre><code>chsh -s /bin/zsh</code></pre>
			<p>Normally, this is enough to make your terminal emulators to use ZSH instead of Bash. You probably just have to restart them. However, there are some terminal emulators that will have a special settings to configure it inside them, which will overwrite your system's default: like Gnome Terminal and Konsole do.</p>
			<p>If that is your case, you can go to their settings, and search for a section where you can choose the command to run as the startup shell. Use <code>/bin/zsh</code> to initiate ZSH.</p>
			<p>If you are asking, you can always revert those changes back to Bash, if it was the default one by using the same command if you need:</p>
			<pre><code>chsh -s /bin/bash</code></pre>
		<h3>Installing River Dreams</h3>
			<p>Now that you have ZSH running as your shell, it is time to install River Dreams.</p>
			<p>First, we need to install some dependencies and see some recomendations for a better experience. If you are using MacOS, you can install these dependencies from their official websites (hyperlinks will be available in the text) or even using <a>Homebrew</a>. On Linux, you can do it too, but you will also find some of them using your distribution's package manager.</p>
			<ul>
				<li>Install <code>gcc</code> and Rust</li>
				<p>These are the tools to compile the source code of River Dreams.</p>
				<p>Even that <code>gcc</code> is not used to compile River Dreams directly, it is needed by Rust to do any compilation.</p>
				<p>You can find more information about how to install Rust in its <a href="https://www.rust-lang.org">official website</a>.</p>
				<p>About the <code>gcc</code>, for example, if you are using Ubuntu or a distribution based on it, you can download it using the following command (sudo priveleges are required to do it):</p>
				<pre><code>sudo apt install -y build-essential</code></pre>
				<li>Install the Noto Sans font family and a monospaced font patched by the Nerd Fonts project.</li>
				<p>These are the fonts that will give access to all the symbols shown in the prompt. As you can run River Dreams using its fallback text feature, installing them is kinda optional, but you will probably want to use them for a better experience.</p>
				<p>The Noto Sans font has a wide range of character for many languages, for that reason you will probably have it installed in your operating system already. If not, you can always download it from its page on the <a href="https://fonts.google.com/noto/specimen/Noto+Sans">Google Fonts website</a>.</p>
				<p>If you are using Ubuntu or a distribution based on it, you can download it using the following command (sudo priveleges are required to do it) if you do not have it installed:</p>
				<pre><code>sudo apt install -y fonts-noto</code></pre>
				<p>Fonts patched by Nerd Fonts are usually distributed in a widely range of Linux distribution's package managers. However, you can always download one from the <a href="https://github.com/ryanoasis/nerd-fonts/releases">Releases</a> page of the Nerd Fonts project on GitHub.</p>
				<li>Install a good terminal emulator</li>
				<p>This is a completly optional dependency, but a fair recommendation: using a terminal that is fast and that can render unicode characters pretty well will give you a smoother experience. For MacOS and Linux, Kitty is a good choice. If you are using Windows, try using Windows Terminal, it alsos will allow you to easily use WSL.</p>
				<p>If you are using Ubuntu or a distribution based on it, you can download Kitty using the following command (sudo priveleges are required to do it):</p>
				<pre><code>sudo apt install -y kitty</code></pre>
				<p>However, you can find more information about how to install Kitty in its <a href="https://github.com/kovidgoyal/kitty">repository</a> on GitHub.</p>
				<p>Kitty uses your user's default shell, which is pretty convenient as the in last section you have learned how to configure it.</p>
			</ul>
