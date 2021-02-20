/***
 * Excerpted from "Practical Vim",
 * published by The Pragmatic Bookshelf.
 * Copyrights apply to this code. It may not be used to create training material,
 * courses, books, articles, and the like. Contact us if you are in doubt.
 * We make no guarantees that this code is fit for any purpose.
 * Visit http://www.pragmaticprogrammer.com/titles/dnvim2 for more book information.
***/
var i;
for (i=1; i <= 100; i++) {
    if(i % 15 == 0) {
        console.log('Fizzbuzz');
    } else if(i % 5 == 0) {
        console.log('Buzz');
    } else if(i % 3 == 0) {
        console.log('Fizz');
    } else {
        console.log(i);
    }
};
