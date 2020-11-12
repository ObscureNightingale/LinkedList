## Linked List

A [Linked List](https://en.wikipedia.org/wiki/Linked_list) is a linear collection of [Nodes](https://en.wikipedia.org/wiki/Node_(computer_science)) where each Node's order is not set by their physical placement in memory, but rather, each Node points to the next.
The collection of nodes represents a sequence.

<br>

## What I did

My implementation of a Linked List is rather very basic. It does not have an explicit method for traversing over the list and returning back the wanted changes (such as `map` & `forEach` ).
Rather, I've only implemented the following methods:

* `append`  - Add an element to the end of the list
* `prepend` - Add an element to the beggining of the list
* `init`    - Return the head of the list (first element)
* `pop`     - Remove the last element from the list and return it
* `shift`   - Remove the first element from the list and return it
* `size`    - Return the number of nodes inside of the list
* `tail`    - Return the tail of the list (last element)
* `has`     - Return a boolean indicating whether or not the specified value is present in any node

<br>

## Method parameter types and function overloading

A few methods contain function overloading, for example: `append` & `prepend` .
They can both take in either a singular element (of type `int` ), or an array of the aforementioned type.

If the parameter type value is `NULL`, that means the function does not require any values to be provided to its parameters.

<br>

| Function  | Parameters (types) | Overloaded |
| --------- | :----------------: | ---------: |
| `append`  |  `int` \| `int[]`  |          ✓ |
| `has`     |       `int`        |            |
| `init`    |        NULL        |            |
| `pop`     |        NULL        |            |
| `prepend` |  `int` \| `int[]`  |          ✓ |
| `shift`   |        NULL        |            |
| `size`    |        NULL        |            |
| `tail`    |        NULL        |            |

<br>

***

<br>

## Author

Authored, and maintained by [Sketchy](https://github.com/SketchyLxve/SketchyLxve)

> Twitter @ [xanny](https://twitter.com/eboy_sleepy) <br>
> Discord @ `xanax#1327` <br>
> Github @ [SketchyLxve](https://github.com/SketchyLxve)