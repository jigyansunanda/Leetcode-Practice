/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let initialValue = init, currentValue = init;
    function increment() {return ++currentValue;}
    function decrement() {return --currentValue;}
    function reset() {currentValue = initialValue; return currentValue;}
    return {increment, decrement, reset};
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */