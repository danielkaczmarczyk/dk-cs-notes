# what would happen if there was no mango sellers?
# - the queue ends up empty eventually
# - as long as there are no circular references, we end our search
# what would happen if there was no mango sellers and we would have a circular reference?
# - the search would continue into infinity
# - to alleviate this problem we need to keep track of people we've already seen

# declaring the graph by hand
graph = {}
graph['you'] = ['bob', 'claire', 'alice']
graph['bob'] = ['anuj', 'peggy']
graph['claire'] = ['tho', 'jonny']
graph['alice'] = ['peggy']
graph['anuj'] = []
graph['peggy'] = ['bob']
graph['tho'] = []
graph['jonny'] = []


# 1. keep a queue containing the people to check
# 2. pop a person off the queue
# 3. check if this person is a mango seller
  # 4a: yes: you're done!
  # 4b: add all their neighbors to the queue
# 5. Loop back to 1!
# 6. if the queue is empty , there are not mango sellers in your network

def sells_mangoes?(person)
  person[-1] == 'm'
end

def bfs(graph)
  queue = []
  queue += graph['you']
  searched = []

  while !queue.empty?
    puts "q: #{queue}"
    puts "s: #{searched}"
    current_person = queue.shift
    puts "looking at #{current_person}"
    if not (searched.include? current_person)
      if sells_mangoes? current_person
        puts "we found the mango seller!: #{current_person}"
        return
      else
        puts "#{current_person} is not selling mangoes. adding their friends to the q"
        queue += graph[current_person]
        searched << current_person
      end
    else
      puts "we already checked if #{current_person} is a mango seller. that person leaves the queue"
    end
  end
  puts "no mango seller found."
end
bfs graph
