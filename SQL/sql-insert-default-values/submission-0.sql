CREATE TABLE products (
  id INTEGER PRIMARY KEY,
  name TEXT,
  stock INTEGER DEFAULT 0
);

-- Do not modify above this line --



INSERT INTO products (id, name, stock)
VALUES (1, 'Apple', 0),
  (2, 'Banana', 0),
  (3, 'Orange', 0);




-- Do not modify below this line --
SELECT * FROM products;
