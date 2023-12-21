CREATE DATABASE IF NOT EXISTS testdb;
USE testdb;

DROP TABLE IF EXISTS checklists;
DROP TABLE IF EXISTS tasks;

CREATE TABLE IF NOT EXISTS tasks (
    id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(255) NOT NULL,
    start_date DATE,
    due_date DATE
);

CREATE TABLE IF NOT EXISTS checklists(
  id INT AUTO_INCREMENT,
  task_id INT, 
  title VARCHAR(255) NOT NULL, 
  is_completed BOOLEAN NOT NULL DEFAULT FALSE, 
  PRIMARY KEY (id, task_id), 
  FOREIGN KEY (task_id) 
      REFERENCES tasks (id) 
      ON UPDATE RESTRICT 
      ON DELETE CASCADE
);

describe tasks;
describe checklists;

INSERT INTO tasks (title, start_date, due_date) VALUES
    ('Task 1', '2023-01-01', '2023-01-10'),
    ('Task 2', '2023-02-15', '2023-02-28'),
    ('Task 3', '2023-03-05', '2023-03-15');

INSERT INTO checklists (task_id, title, is_completed) VALUES
    (1, 'Item 1', true),
    (1, 'Item 2', false),
    (2, 'Item 1', false),
    (2, 'Item 2', true),
    (3, 'Item 1', false);

SELECT * FROM tasks;
SELECT * FROM checklists;
