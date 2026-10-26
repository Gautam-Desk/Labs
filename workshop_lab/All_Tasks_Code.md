# Simple Code for All Tasks

Each task below has its own complete HTML example. You can also open the separate pages from the [task index](./Simple_Tasks/index.html).

## Basic HTML

### Clickable Image

File: [`clickable-image.html`](./Simple_Tasks/basic-html/clickable-image.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Clickable Image</title></head>
<body>
  <h1>Click the Image</h1>
  <a href="https://example.com">
    <img src="../../assignment-1/image.jpeg" alt="Sample picture" width="200">
  </a>
</body>
</html>
```

### Table with Spanning Heading

File: [`complex-table.html`](./Simple_Tasks/basic-html/complex-table.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Table with Spanning Heading</title></head>
<body>
  <h1>Student Results</h1>
  <table border="1">
    <tr><th colspan="3">Exam Scores</th></tr>
    <tr><th>Name</th><th>HTML</th><th>CSS</th></tr>
    <tr><td>Asha</td><td>85</td><td>90</td></tr>
    <tr><td>Ravi</td><td>78</td><td>88</td></tr>
  </table>
</body>
</html>
```

### Description List

File: [`description-list.html`](./Simple_Tasks/basic-html/description-list.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Description List</title></head>
<body>
  <h1>Web Design Terms</h1>
  <dl>
    <dt>HTML</dt>
    <dd>Builds the structure of a web page.</dd>
    <dt>CSS</dt>
    <dd>Styles the web page.</dd>
  </dl>
</body>
</html>
```

### Headings and Paragraphs

File: [`headings.html`](./Simple_Tasks/basic-html/headings.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Headings and Paragraphs</title></head>
<body>
  <h1>My Web Page</h1>
  <h2>About Me</h2>
  <p>This is a paragraph on my web page.</p>
  <p>I am learning how to make websites with HTML.</p>
</body>
</html>
```

### Inline Styles

File: [`inline-style.html`](./Simple_Tasks/basic-html/inline-style.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Inline Styles</title></head>
<body>
  <h1 style="color: navy;">Welcome</h1>
  <p style="font-size: 18px;">This page uses simple inline styles.</p>
  <a href="https://example.com">Visit a website</a>
</body>
</html>
```

### Ordered List

File: [`ordered-list.html`](./Simple_Tasks/basic-html/ordered-list.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Ordered List</title></head>
<body>
  <h1>My To-Do List</h1>
  <ol>
    <li>Study HTML</li>
    <li>Practice CSS</li>
    <li>Build a web page</li>
  </ol>
</body>
</html>
```

### Registration Form

File: [`registration-form.html`](./Simple_Tasks/basic-html/registration-form.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Registration Form</title></head>
<body>
  <h1>Registration Form</h1>
  <form>
    <p><label>Name: <input type="text" name="name"></label></p>
    <p><label>Email: <input type="email" name="email"></label></p>
    <button type="submit">Submit</button>
  </form>
</body>
</html>
```

### Simple Table

File: [`simple-table.html`](./Simple_Tasks/basic-html/simple-table.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Simple Table</title></head>
<body>
  <h1>Student List</h1>
  <table border="1">
    <tr><th>Name</th><th>Age</th></tr>
    <tr><td>Asha</td><td>20</td></tr>
    <tr><td>Ravi</td><td>21</td></tr>
  </table>
</body>
</html>
```

### Text Formatting

File: [`text-formatting.html`](./Simple_Tasks/basic-html/text-formatting.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Text Formatting</title></head>
<body>
  <h1>Text Formatting</h1>
  <p><strong>This text is important.</strong></p>
  <p><em>This text is emphasized.</em></p>
  <p>Water is H<sub>2</sub>O.</p>
  <p>Two squared is 2<sup>2</sup>.</p>
</body>
</html>
```

### Unordered List

File: [`unordered-list.html`](./Simple_Tasks/basic-html/unordered-list.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Unordered List</title></head>
<body>
  <h1>My Hobbies</h1>
  <ul>
    <li>Reading</li>
    <li>Listening to music</li>
    <li>Playing sports</li>
  </ul>
</body>
</html>
```

### HTML Examples

File: [`workshop-index.html`](./Simple_Tasks/basic-html/workshop-index.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>HTML Examples</title></head>
<body>
  <h1>HTML Examples</h1>
  <ul>
    <li><a href="headings.html">Headings and paragraphs</a></li>
    <li><a href="ordered-list.html">Ordered list</a></li>
    <li><a href="simple-table.html">Simple table</a></li>
    <li><a href="registration-form.html">Registration form</a></li>
  </ul>
</body>
</html>
```

## CSS

### Style a Link

File: [`link-style.html`](./Simple_Tasks/css/link-style.html)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Style a Link</title>
  <style>
    a { color: blue; }
    a:hover { color: red; }
  </style>
</head>
<body>
  <h1>Link Styling</h1>
  <p><a href="https://example.com">Move the pointer over this link.</a></p>
</body>
</html>
```

### Margin and Padding

File: [`spacing.html`](./Simple_Tasks/css/spacing.html)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Margin and Padding</title>
  <style>
    .box { margin: 20px; padding: 15px; border: 1px solid black; }
  </style>
</head>
<body>
  <h1>Spacing</h1>
  <div class="box">Margin is outside the border. Padding is inside the border.</div>
</body>
</html>
```

### CSS Text Properties

File: [`text-properties.html`](./Simple_Tasks/css/text-properties.html)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
  <title>CSS Text Properties</title>
  <style>
    h1 { color: darkblue; text-align: center; }
    p { font-size: 18px; line-height: 1.5; }
  </style>
</head>
<body>
  <h1>Learn CSS</h1>
  <p>CSS can change the color, size, and alignment of text.</p>
</body>
</html>
```

### CSS Z-Index

File: [`z-index.html`](./Simple_Tasks/css/z-index.html)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
  <title>CSS Z-Index</title>
  <style>
    .box { position: absolute; width: 140px; height: 90px; padding: 8px; }
    .back { left: 30px; top: 100px; background: lightblue; z-index: 1; }
    .front { left: 80px; top: 140px; background: coral; z-index: 2; }
  </style>
</head>
<body>
  <h1>Boxes and Z-Index</h1>
  <div class="box back">Back box</div>
  <div class="box front">Front box</div>
</body>
</html>
```

## Assignment 1

### About

File: [`about.html`](./Simple_Tasks/assignment-1/about.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>About</title></head>
<body>
  <h1>About Us</h1>
  <p>We are learning how to build websites.</p>
  <a href="home.html">Back to Home</a>
</body>
</html>
```

### Bookstore

File: [`bookstore.html`](./Simple_Tasks/assignment-1/bookstore.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Bookstore</title></head>
<body>
  <h1>Online Bookstore</h1>
  <ul>
    <li>HTML for Beginners — $10</li>
    <li>Learning CSS — $12</li>
  </ul>
  <a href="catalogue.html">View the catalogue</a>
</body>
</html>
```

### Decorative Text

File: [`calligram.html`](./Simple_Tasks/assignment-1/calligram.html)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Decorative Text</title>
  <style>
    .poem { color: purple; font-size: 24px; text-align: center; line-height: 1.5; }
  </style>
</head>
<body>
  <h1>A Small Poem</h1>
  <p class="poem">A little word<br>can make a page<br>feel like a poem.</p>
</body>
</html>
```

### Shopping Cart

File: [`cart.html`](./Simple_Tasks/assignment-1/cart.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Shopping Cart</title></head>
<body>
  <h1>Shopping Cart</h1>
  <p>HTML for Beginners — $10</p>
  <p><strong>Total: $10</strong></p>
  <button type="button">Checkout</button>
</body>
</html>
```

### Book Catalogue

File: [`catalogue.html`](./Simple_Tasks/assignment-1/catalogue.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Book Catalogue</title></head>
<body>
  <h1>Book Catalogue</h1>
  <table border="1">
    <tr><th>Book</th><th>Price</th></tr>
    <tr><td>HTML for Beginners</td><td>$10</td></tr>
    <tr><td>Learning CSS</td><td>$12</td></tr>
  </table>
  <p><a href="cart.html">Go to the cart</a></p>
</body>
</html>
```

### Assignment Home

File: [`home.html`](./Simple_Tasks/assignment-1/home.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Assignment Home</title></head>
<body>
  <h1>Home Page</h1>
  <p>Welcome to my website.</p>
  <a href="about.html">About us</a>
</body>
</html>
```

### Login Form

File: [`login.html`](./Simple_Tasks/assignment-1/login.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Login Form</title></head>
<body>
  <h1>Login</h1>
  <form>
    <p><label>Username: <input type="text" name="username"></label></p>
    <p><label>Password: <input type="password" name="password"></label></p>
    <button type="submit">Login</button>
  </form>
</body>
</html>
```

### Moving Text

File: [`moving-text.html`](./Simple_Tasks/assignment-1/moving-text.html)

```html
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1">
  <title>Moving Text</title>
  <style>
    .moving-text { width: max-content; animation: move 3s ease-in-out infinite alternate; }
    @keyframes move { to { transform: translateX(150px); } }
  </style>
</head>
<body>
  <h1>Moving Text</h1>
  <p class="moving-text">Welcome to my page!</p>
</body>
</html>
```

### Nested List

File: [`nested-list.html`](./Simple_Tasks/assignment-1/nested-list.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Nested List</title></head>
<body>
  <h1>States and Cities</h1>
  <ol>
    <li>Maharashtra
      <ul><li>Mumbai</li><li>Pune</li></ul>
    </li>
    <li>Gujarat
      <ul><li>Ahmedabad</li></ul>
    </li>
  </ol>
</body>
</html>
```

### Registration Form

File: [`registration.html`](./Simple_Tasks/assignment-1/registration.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Registration Form</title></head>
<body>
  <h1>Register</h1>
  <form>
    <p><label>Name: <input type="text" name="name"></label></p>
    <p><label>Email: <input type="email" name="email"></label></p>
    <p><label>Password: <input type="password" name="password"></label></p>
    <button type="submit">Create account</button>
  </form>
</body>
</html>
```

### Page Section Link

File: [`section-link.html`](./Simple_Tasks/assignment-1/section-link.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Page Section Link</title></head>
<body>
  <h1>Page Sections</h1>
  <p><a href="#contact">Jump to Contact</a></p>
  <p style="height: 500px;">Scroll down to find the contact section.</p>
  <h2 id="contact">Contact</h2>
  <p>Email: hello@example.com</p>
</body>
</html>
```

### Three Images

File: [`three-images.html`](./Simple_Tasks/assignment-1/three-images.html)

```html
<!DOCTYPE html>
<html lang="en">
<head><meta charset="UTF-8"><meta name="viewport" content="width=device-width, initial-scale=1"><title>Three Images</title></head>
<body>
  <h1>Three Pictures</h1>
  <img src="../../assignment-1/image.jpeg" alt="First picture" width="150">
  <img src="../../assignment-1/man.jpeg" alt="Second picture" width="150">
  <img src="../../assignment-1/climb.jpeg" alt="Third picture" width="150">
</body>
</html>
```
