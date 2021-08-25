Text processing

- [ ] grep
- [ ] sort
- [ ] uniq
- [ ] cut
- [ ] wc
- [ ] sed
- [ ] strings
- [ ] head
- [ ] tail
- [ ] awk

Process management

- [ ] ps
- [ ] fg
- [ ] bg
- [ ] jobs
- [ ] kill

Filesystem

- [ ] cd
- [ ] cat
- [ ] cp
- [ ] rm
- [ ] ls
- [ ] mv
- [ ] ln
- [ ] file
- [ ] chmod
- [ ] chown
- [ ] du
- [ ] mkdir
- [ ] mkfifo

Shell use

- [ ] man
- [ ] help
- [ ] echo
- [ ] apropos
- [ ] tee
- [ ] test
- [ ] xargs

Completion Exercise

Write a Bash program that shows summary information from Wikipedia. wiki walrus should show the
first sentence of the “Walrus” article, along with a list of section headings. wiki walrus anatomy should
show the first sentence of the anatomy section, along with a list of subsection headings.
• You are welcome to use curl to retrieve the page itself, as well as any commands that you’d
expect to find on a typical Unix family OS distribution.
• As a stretch goal, add support for tab completion in Bash, ie wiki walr[tab] should expand to
walrus, and wiki walrus anat[tab] should expand to anatomy.
• As another stretch goal, add a flag to support querying multiple pages in parallel.
