# 0x0B. Menger sponge

Function that draws a 2D Menger Sponge

* Prototype: `void menger(int level);`
* Where `level` is the level of the Menger Sponge to draw
* If `level` is lower than `0`, your function must do nothing
* Compile using the `ld` flag `-lm`, `math` library is allowed.

**Format:**
* Here, we will only draw a 2D version of the Menger sponge, but the principle is the same
* A level `N` sponge is a 3x3 square of level `N-1` sponges, except for the center one, which is left empty
* A level 0 sponge is represented by the `#` character

* Examples:
  * A level 0 sponge is a simple 1x1 square
  * A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
  * A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
  * …
* TIP: The size of a level `N` Menger sponge is calculated as follows: `3^N`

**Resources:**
* [Menger Sponge](https://en.wikipedia.org/wiki/Menger_sponge)
* [Sierpiński carpet](https://en.wikipedia.org/wiki/Sierpi%C5%84ski_carpet)

### Author:
* Tatiana Orejuela Zapata | [Github](https://github.com/tatsOre)

##### Specializations - Interview Preparation ― Algorithms
##### March, 2021.