program_text=$(cat "$1")

function run() {
  racket -e "$program_text"
}

run
