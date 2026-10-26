# Simple Web Design Tasks

Each task now also has its own ready-to-open HTML file in the [Simple_Tasks](./Simple_Tasks/) folder. Open [Simple_Tasks/index.html](./Simple_Tasks/index.html) to choose a task. The examples below remain here as a quick reference, and the original files are unchanged.

## Basic HTML

### `page.html` — headings and text

```html
<h1>My Web Page</h1>
<h2>About Me</h2>
<p>This is a paragraph.</p>
<p><b>Bold</b> and <i>italic</i> text.</p>
```

### `demo_page.html` — text formatting

```html
<h1>Text Formatting</h1>
<p><strong>Important text</strong></p>
<p><em>Emphasized text</em></p>
<p>Water is H<sub>2</sub>O.</p>
<p>Two squared is 2<sup>2</sup>.</p>
```

### `list.html` — ordered list

```html
<h2>My To-Do List</h2>
<ol>
  <li>Study HTML</li>
  <li>Practice CSS</li>
  <li>Build a page</li>
</ol>
```

### `Page_list.html` — unordered list

```html
<h2>My Hobbies</h2>
<ul>
  <li>Reading</li>
  <li>Music</li>
  <li>Sports</li>
</ul>
```

### `Description_list.html` — terms and descriptions

```html
<h2>Web Terms</h2>
<dl>
  <dt>HTML</dt>
  <dd>Builds the structure of a web page.</dd>
  <dt>CSS</dt>
  <dd>Styles a web page.</dd>
</dl>
```

### `table.html` — simple table

```html
<table border="1">
  <tr><th>Name</th><th>Age</th></tr>
  <tr><td>Asha</td><td>20</td></tr>
  <tr><td>Ravi</td><td>21</td></tr>
</table>
```

### `complex_table.html` — table with a heading across columns

```html
<table border="1">
  <tr><th colspan="3">Student Results</th></tr>
  <tr><th>Name</th><th>HTML</th><th>CSS</th></tr>
  <tr><td>Asha</td><td>85</td><td>90</td></tr>
</table>
```

### `form1.html` — basic form

```html
<h1>Registration</h1>
<form>
  <label>Name: <input type="text" name="name"></label><br>
  <label>Email: <input type="email" name="email"></label><br>
  <button type="submit">Submit</button>
</form>
```

### `image_hyprlink.html` — clickable image

```html
<a href="https://example.com">
  <img src="image.jpeg" alt="Example image" width="200">
</a>
```

### `style_Attribute.html` — simple inline styles and links

```html
<h1 style="color: navy;">Welcome</h1>
<p style="font-size: 18px;">This is my page.</p>
<a href="https://example.com">Visit a website</a>
```

### `index.html` — links to the examples

```html
<h1>Web Design Tasks</h1>
<ul>
  <li><a href="page.html">Text and headings</a></li>
  <li><a href="list.html">Lists</a></li>
  <li><a href="table.html">Tables</a></li>
  <li><a href="form1.html">Forms</a></li>
</ul>
```

## CSS

### `css/csslink.html` — link styling

```html
<style>
  a { color: blue; }
  a:hover { color: red; }
</style>
<a href="https://example.com">Move the pointer over this link</a>
```

### `css/margin_padding.html` — spacing

```html
<style>
  .box {
    margin: 20px;
    padding: 15px;
    border: 1px solid black;
  }
</style>
<div class="box">This box has space around and inside it.</div>
```

### `css/Textpro.html` — text properties

```html
<style>
  h1 { color: darkblue; text-align: center; }
  p { font-size: 18px; line-height: 1.5; }
</style>
<h1>Learn CSS</h1>
<p>CSS can change how text looks.</p>
```

### `css/Z_indexing.html` — place one box over another

```html
<style>
  .box { position: absolute; width: 120px; height: 80px; }
  .back { background: lightblue; z-index: 1; }
  .front { background: coral; left: 40px; top: 30px; z-index: 2; }
</style>
<div class="box back"></div>
<div class="box front"></div>
```

## Assignment 1

### `assignment-1/index.html` and `assignment-1/about.html` — two linked pages

Put this link on the home page:

```html
<h1>Home Page</h1>
<a href="about.html">About us</a>
```

Put this on `about.html`:

```html
<h1>About Us</h1>
<p>Welcome to our website.</p>
<a href="index.html">Home</a>
```

### `assignment-1/bookstore.html` — a small bookstore

```html
<h1>Book Store</h1>
<ul>
  <li>HTML for Beginners — $10</li>
  <li>Learning CSS — $12</li>
</ul>
<a href="catalogue.html">See the catalogue</a>
```

### `assignment-1/catalogue.html` — book catalogue

```html
<h1>Book Catalogue</h1>
<table border="1">
  <tr><th>Book</th><th>Price</th></tr>
  <tr><td>HTML for Beginners</td><td>$10</td></tr>
  <tr><td>Learning CSS</td><td>$12</td></tr>
</table>
```

### `assignment-1/cart.html` — shopping cart

```html
<h1>Shopping Cart</h1>
<p>HTML for Beginners — $10</p>
<p>Total: $10</p>
<button>Checkout</button>
```

### `assignment-1/login.html` — login form

```html
<h1>Login</h1>
<form>
  <label>Username: <input name="username"></label><br>
  <label>Password: <input type="password" name="password"></label><br>
  <button type="submit">Login</button>
</form>
```

### `assignment-1/registration.html` — registration form

```html
<h1>Register</h1>
<form>
  <label>Name: <input name="name"></label><br>
  <label>Email: <input type="email" name="email"></label><br>
  <label>Password: <input type="password" name="password"></label><br>
  <button type="submit">Create account</button>
</form>
```

### `assignment-1/hyperlink.html` — jump to a section

```html
<a href="#contact">Go to Contact</a>
<h2 id="contact">Contact</h2>
<p>Email: hello@example.com</p>
```

### `assignment-1/calligram.html` — decorative text

```html
<style>
  .poem { color: purple; font-size: 24px; text-align: center; }
</style>
<p class="poem">A small poem<br>in the middle<br>of the page</p>
```

### `assignment-1/marquee.html` — moving text

```html
<style>
  .moving-text { animation: move 5s linear infinite alternate; }
  @keyframes move { to { transform: translateX(100px); } }
</style>
<p class="moving-text">Welcome to my page!</p>
```

### `assignment-1/nestedord.html` — nested lists

```html
<ol>
  <li>Maharashtra
    <ul>
      <li>Mumbai</li>
      <li>Pune</li>
    </ul>
  </li>
  <li>Gujarat
    <ul><li>Ahmedabad</li></ul>
  </li>
</ol>
```

### `assignment-1/threeimg.html` — show three images

```html
<img src="image.jpeg" alt="First picture" width="150">
<img src="man.jpeg" alt="Second picture" width="150">
<img src="climb.jpeg" alt="Third picture" width="150">
```

## Run a task

1. Copy the example into a file ending in `.html`.
2. Save it and open the file in a web browser.
3. For the three-image example, keep the image files beside the HTML file.
