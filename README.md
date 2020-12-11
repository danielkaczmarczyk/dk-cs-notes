# teach-yourself-cs-curriculum

This document is my record of work towards a Self-Taught equivalent of a CS degree. The core curriculum is as perscribed by Oz Nove and Myles Byrne, authors of [teachyourselfcs.com](https://teachyourselfcs.com), but consists of additional resources that I have completed / am interested in. If you want to ask questions about the core curriculum, all the answers are to be found at the link above.

The purpose of this repository is twofold - to keep myself organised and accountable, and also to be able to share my experience with other people who are undertaking a similar challenge of completing this curriculum.

Join my [Discord server](https://discord.gg/HjNfTnu9aQ) if you're interested in working through that curriculum too!

## Table of Contents

- [Progress](#progress)
- [General Findings](#general-findings)
- [Notes on different parts of the course](#course)
- [Diary/Log](#diary/log)

## Progress

### teachyourselfcs core

Resource | Type | Topic | Status | Source
---------|------|-------|--------|-------
Composing Programs | Book | Programming | in progress | [composing programs](https://composingprograms.com/) 
Structure and Implementation of Computer Programs | Book | Programming | in progress | [tycs](https://teachyourselfcs.com/)
Brian Harvey's Berkeley CS 61A | Video |  Programming | in progress | [videos](https://archive.org/details/ucberkeley-webcast-PL3E89002AA9B9879E?sort=titleSorter)
Computer Systems: A Programmer's Perspective | Book | Computer Architecture | queued | [tycs](https://teachyourselfcs.com/)
Berkeley CS 61C | Video | Computer Architecture | queued | [tycs](https://teachyourselfcs.com/)
The Algorithm Design Manual | Book | Algorithms and Data Structures | queued | [tycs](https://teachyourselfcs.com/)
Steven Skiena's Lectures | Video | Algorithms and Data Structures | queued | [tycs](https://teachyourselfcs.com/)
Mathematics for Computer Science | Book | Math for CS | queued | [tycs](https://teachyourselfcs.com/)
Tom Leighton's MIT 6.042J | Video | Math for CS | queued | [tycs](https://teachyourselfcs.com/)
Operating Systems: Three Easy Pieces | Book | Operating Systems | queued | [tycs](https://teachyourselfcs.com/)
Berkeley CS 162 | Video | Operating Systems | queued | [tycs](https://teachyourselfcs.com/)
Computer Networking: A Top-Down Approach | Book | Computer Networking | queued | [tycs](https://teachyourselfcs.com/)
Stanford CS 144 | Video | Computer Networking | queued | [tycs](https://teachyourselfcs.com/)
Readings in Database Systems | Book | Databases | queued | [tycs](https://teachyourselfcs.com/)
Joe Hellerstein's Berkeley CS 186 | Video | Databases | queued | [tycs](https://teachyourselfcs.com/)
Crafting Interpreters | Book | Languages and Compilers | queued | [tycs](https://teachyourselfcs.com/)
Alex Aiken's course on edX | Video | Languages and Compilers | queued | [tycs](https://teachyourselfcs.com/)
Designing Data-Intensive Applications by Martin Kleppmann | Book | Distributed Systems | queued | [tycs](https://teachyourselfcs.com/)
MIT 6.824 | Video | Distributed Systems | queued | [tycs](https://teachyourselfcs.com/)

### Other Resources I've Found Valuable

Resource | Type | Topic | Status | Source
---------|------|-------|--------|-------
MIT Missing Semester | Videos | Tooling | in progress | [source](https://missing.csail.mit.edu/)
YDKJS Book Series (all) | Book | JS | completed | [ydkjs](https://github.com/getify/You-Dont-Know-JS)
tmux: productive mouse-free development | Book | tmux | in progress | [no link yet]() 
William Shotts - The Linux Command Line A Complete Introduction No Starch Press (2019) | Book | linux | in progress | [no link yet]() 
Drew Neil - Modern Vim Craft Your Development Environment with Vim 8 and Neovim-Pragmatic Bookshelf (2018) | Book | vim | in progress | [no link yet]()
CS50 | Video | CS | 2020 queued | [no link yet]()
C.O.D.E. by Charles Petzold | Book | Programming | completed | [amazon](https://www.amazon.co.uk/Code-Language-Computer-Hardware-Software/dp/0735611319/ref=sr_1_1?adgrpid=50764275022&dchild=1&gclid=CjwKCAiAnvj9BRA4EiwAuUMDfyT5n7YXKm936Z8c81dv1Zk3kFNT3XOw6WG6fv90hR5zkOFLpAvgpxoCnF0QAvD_BwE&hvadid=259073923662&hvdev=c&hvlocint=9045954&hvlocphy=20853&hvnetw=g&hvqmt=b&hvrand=15507896899033965839&hvtargid=kwd-300578219443&hydadcr=17607_1775410&keywords=charles+petzold+code&qid=1606314907&sr=8-1&tag=googhydr-21)

## General Findings

### Biggest Challenges

By far the most challenging part of taking a self-guided course like this is not doing it with other people. I have started a [Discord Server](https://discord.gg/HjNfTnu9aQ) for people who are also working through that curriculum, and it is helpful to exchange experiences and advice. Be ready for a lot of frustration trying to find solutions to your problems without a centralised place for people who are doing something similar hang out. Luckily there are groups centered around various resources and topics (SICP has a big community).

### First few weeks

Working through the first month of the curriculum has been a challenge - especially in guiding my learning and scheduling sessions. Working on your own you have to answer questions regarding what to study, for how long, and what are measurable deliverables. I've iterated over a few frameworks and I've found that having a clear view of a week ahead with a minimum goal works best for me. The study topics are organised in sections as per the teachyourselfcs curriculum, so for example:

I'm working through the Programming section, directly on Composing Programs, therefore every day I spend 3-5h on the main topic. To add variety, and for pleasure of it (I find it brings me the most joy to do) I also schedule daily code challenge sessions (leetcode / codewars / advent of code etc). That takes up a couple hours, and I use it to not only brush up on Algorithms, Data Structures, and Problem Solving, but also polish a language of my choice that I'm currently working with. As a tetriary topic of the day I include meta-study, on the tooling that I am using. [Therefore there's always a 30-60 minute session on vim / tmux / shell scripting etc.](#rethinking-development-process-and-tooling). Lastly, I make sure to review [recent knowledge.](#flashcards-flashcards-flashcards)

### Flashcards, flashcards, flashcards.

I'm using a [tool called Anki](https://apps.ankiweb.net/) to organise my knowledge into bite-sized reviewable flashcards. It's an incredible and simple tool that enabled me to actually retrieve a lot of knowledge. Simply as I read / watch / code, every time I stumble upon a nugget of information, I distill it to a fact, write it down into the flashcard database and review them daily. Time invested in those is worth its weight in gold for me.

### Rethinking development process and tooling

Working on the core Computer Science content is one thing, but becoming more proficient with the tooling while doing so is a completely different topic. I've been used to working in VSCode + separate terminal setup, but due to the fact that I am working on two different computers often (macos and linux), I need a reliable and replicable setup on both machines. For that reason I have narrowed the text editing and all work on a computer to using `tmux`, and `vim`. If you're not sure where to start with that, [I suggest a great series of video lectures](https://www.youtube.com/channel/UCuXy5tCgEninup9cGplbiFw).

One example of a simple gain is to use a tool like [nodemon](https://github.com/remy/nodemon) to speed up iteration through the coding challenges / exercises. Do not ignore it for just being a JS tool, take a look at the documentation and the `--exec` flag.

### Command-Line tools i highly recommend getting

- `fzf` for fuzzy matching searches in text files. a good alternative to grep/ripgrep for quick searches
- `broot` for a very neat alternative to `ls -R` or `tree` commands
- `nnn` a more advanced alt to `broot`
- `ranger` for navigating files with `vi` bindings 
- `tldr` for snippets of usage examples of tools, saves you stackoverflow googling
- `pretzo` [for a really pretty](https://github.com/sorin-ionescu/prezto) `zsh` prompt. 

### Course

#### Programming

#### Composing Programs

I found [this article](https://accu.org/journals/overload/16/86/golodetz_1506/) useful while digesting Partition Trees described in section 2.3.6.

### Diary/Log

Blog-like selection of thoughts. Unstructured. Writing those helps me think about the process of learning more clearly. 

#### 11th December 2020

For all this to work I need a sustainable system through which I am going to be able to measure - how well I'm doing, and am I doing enough. Learning on one's own can become chaotic and unstructured, and to countermeasure that, I decided to time myself study (not to a second, but let's say, to a 15-20 min period). Instead of using a schedule based on a week-plan, I am using a table in Google Sheets to log planned learning, with time spent on it, for the ease of querying, filtering, and tallying. This approach leaves me with raw data on my efforts (at least). It has worked for me to use a fitbit that way -- measuring effort draws better results for me, I find. 

I have deleted all the repos for course material (I did create one for each course/book, but it has been proven to be a lot of redundant work since code included in those repositories is just a scattered selection of snippets. All the code for this process therefore is currently included in this repository and that's how I intend to keep it. Also, the reason I've done it in the first place is that I failed at partitioning my linux laptop's hard drive and I'm currently reinstalling Ubuntu and I've found copying all the repos to be a lot of work.

