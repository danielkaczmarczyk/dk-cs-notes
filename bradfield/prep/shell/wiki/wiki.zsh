#!/bin/zsh

# wiki
#
# typing `wiki walrus` should show the first sentence of the "Walrus" article, along with a
# list of of section headings. 
#
# `wiki walrus anatomy` should show the first sentence of the anatomy section, along with
# a list of subsection headings.
#
# use curl to retrieve the page itself (and other various commands to be found on a unix sys)
#
# add support for tab completion, ie `wiki walr[tab]` should expand to walrus, and 
# `wiki walurs anat[tab]` should expand to anatomy.
#
# add support via a flag to query multiple pages in parralel
#
# http://info2html.sourceforge.net/cgi-bin/info2html-demo/info2html?%28bash.info.gz%29Programmable%2520Completion
# https://www.geeksforgeeks.org/shell-script-to-scrap-the-definition-of-a-word-from-wikipedia/


set -e


