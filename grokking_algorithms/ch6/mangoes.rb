graph = {}

graph['you'] = ['bob', 'claire', 'alice']
graph['bob'] = ['anuj', 'peggy']
graph['claire'] = ['thom', 'jonny']
graph['alice'] = ['peggy']
graph['anuj'] = []
graph['peggy'] = []
graph['thom'] = []
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

queue = []

queue += graph['you']

while !queue.empty?
  pp queue
  current_person = queue.shift
  puts "looking at #{current_person}"
  if sells_mangoes? current_person
    puts "we found the mango seller!: #{current_person}"
    return
  else
    puts "#{current_person} is not selling mangoes. adding their friends to the q"
    queue += graph[current_person]
  end
end


# what would happen if there was no mango sellers?

# what would happen if there was no mango sellers and we would have a circular reference?