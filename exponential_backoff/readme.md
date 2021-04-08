# Exponential Backoff

This is a simulation of a exponential backoff situation. The logic for the simulation can be found in `index.js`.

## Running

Simply run `node index.js` with node version 7.6 or higher. You can observe the output of the program as sent to stdout. You will observe logs of my program attempting to contact a mock server, which is configured to return a failed response 85% of time. At the end of the procedure, you will see a short summary of the process. For best results and a variety of events encountered, best to run it a few times.

## Comments

For the sake of encapsulation allow every function to have its own internal log of calls and procedures, mostly for presentation purposes for this task.
