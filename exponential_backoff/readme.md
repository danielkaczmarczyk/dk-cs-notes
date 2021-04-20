# Exponential Backoff

This is a little simulation of a exponential backoff implementation in node. The logic for the simulation can be found in `index.js`, and other files serve as various helpers and utilities for presentation. You can find more information about the 'why' [on my blog](https://reversepolishnotation.com/exponential%20backoff/).

## Running

Simply run `node index.js` with node version 7.6 or higher. You can observe the output of the program as sent to stdout. You will observe logs of my program attempting to contact a mock server, which is configured to return a failed response 85% of time. At the end of the procedure, you will see a short summary of the process. For best results and a variety of events encountered, best to run it a few times.

Example output:

```
Start simulating the exponential backoff procedure
---------------------------------------------------
--LOG: 2021-04-20T21:18:49.457Z call 1 attempted...
--LOG: 2021-04-20T21:18:50.721Z call 1 failed. error: <TRAGIC FAILURE>
--LOG: 2021-04-20T21:18:50.721Z call 2 attempted...
--LOG: 2021-04-20T21:18:50.721Z backing off
--LOG: 2021-04-20T21:18:50.721Z -365ms jitter amount applied, 635ms total backoff time
--LOG: 2021-04-20T21:18:53.865Z call 2 failed. error: <TRAGIC FAILURE>
--LOG: 2021-04-20T21:18:53.865Z call 3 attempted...
--LOG: 2021-04-20T21:18:53.866Z backing off
--LOG: 2021-04-20T21:18:53.866Z -105ms jitter amount applied, 1895ms total backoff time
--LOG: 2021-04-20T21:18:58.147Z call 3 failed. error: <TRAGIC FAILURE>
--LOG: 2021-04-20T21:18:58.147Z call 4 attempted...
--LOG: 2021-04-20T21:18:58.147Z backing off
--LOG: 2021-04-20T21:18:58.147Z 34ms jitter amount applied, 4034ms total backoff time
--LOG: 2021-04-20T21:19:04.408Z call 4 successful. result: <SUCCESSFUL RESPONSE>
--LOG: 2021-04-20T21:19:04.408Z procedure successful.
--LOG: 2021-04-20T21:19:04.410Z total time: 14s 950917701ns
{
  eventsLog: [
    '2021-04-20T21:18:49.457Z call 1 attempted...',
    '2021-04-20T21:18:50.721Z call 1 failed. error: <TRAGIC FAILURE>',
    '2021-04-20T21:18:50.721Z call 2 attempted...',
    '2021-04-20T21:18:50.721Z backing off',
    '2021-04-20T21:18:50.721Z -365ms jitter amount applied, 635ms total backoff time',
    '2021-04-20T21:18:53.865Z call 2 failed. error: <TRAGIC FAILURE>',
    '2021-04-20T21:18:53.865Z call 3 attempted...',
    '2021-04-20T21:18:53.866Z backing off',
    '2021-04-20T21:18:53.866Z -105ms jitter amount applied, 1895ms total backoff time',
    '2021-04-20T21:18:58.147Z call 3 failed. error: <TRAGIC FAILURE>',
    '2021-04-20T21:18:58.147Z call 4 attempted...',
    '2021-04-20T21:18:58.147Z backing off',
    '2021-04-20T21:18:58.147Z 34ms jitter amount applied, 4034ms total backoff time',
    '2021-04-20T21:19:04.408Z call 4 successful. result: <SUCCESSFUL RESPONSE>',
    '2021-04-20T21:19:04.408Z procedure successful.',
    '2021-04-20T21:19:04.410Z total time: 14s 950917701ns'
  ],
  result: '<SUCCESSFUL RESPONSE>'
}
End of the exponential backoff procedure simulation
```
