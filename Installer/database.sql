-- Vehicle Rental System - MySQL schema
-- You do NOT have to run this file: the program creates the same database and tables by itself
-- the first time it connects. It is here for reference, or to prepare a server by hand:
--   mysql -u root -p < database.sql

CREATE DATABASE IF NOT EXISTS vehicle_rental CHARACTER SET utf8mb4;
USE vehicle_rental;

CREATE TABLE IF NOT EXISTS owners (
  id INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(100) NOT NULL,
  nic VARCHAR(12) NOT NULL UNIQUE,
  phone VARCHAR(10) NOT NULL,
  address VARCHAR(200) NOT NULL,
  bank_account VARCHAR(60) NOT NULL
);

CREATE TABLE IF NOT EXISTS customers (
  id INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(100) NOT NULL,
  nic VARCHAR(12) NOT NULL UNIQUE,
  phone VARCHAR(10) NOT NULL,
  address VARCHAR(200) NOT NULL
);

CREATE TABLE IF NOT EXISTS vehicles (
  id INT AUTO_INCREMENT PRIMARY KEY,
  plate_number VARCHAR(20) NOT NULL UNIQUE,
  vehicle_type VARCHAR(10) NOT NULL,
  brand VARCHAR(50) NOT NULL,
  model VARCHAR(50) NOT NULL,
  model_year INT NOT NULL,
  seats INT NOT NULL,
  fuel VARCHAR(20) NOT NULL,
  owner_daily_amount DECIMAL(12,2) NOT NULL,
  status VARCHAR(10) NOT NULL,
  owner_id INT NOT NULL,
  FOREIGN KEY (owner_id) REFERENCES owners(id)
);

CREATE TABLE IF NOT EXISTS drivers (
  id INT AUTO_INCREMENT PRIMARY KEY,
  name VARCHAR(100) NOT NULL,
  nic VARCHAR(12) NOT NULL UNIQUE,
  phone VARCHAR(10) NOT NULL,
  address VARCHAR(200) NOT NULL,
  licence_number VARCHAR(30) NOT NULL UNIQUE,
  licence_expiry DATE NOT NULL,
  daily_charge DECIMAL(12,2) NOT NULL,
  is_busy TINYINT(1) NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS bookings (
  id INT AUTO_INCREMENT PRIMARY KEY,
  customer_id INT NOT NULL,
  vehicle_id INT NOT NULL,
  driver_id INT NULL,
  from_date DATE NOT NULL,
  to_date DATE NOT NULL,
  days INT NOT NULL,
  vehicle_daily_rate DECIMAL(12,2) NOT NULL,
  driver_daily_charge DECIMAL(12,2) NOT NULL,
  vehicle_cost DECIMAL(12,2) NOT NULL,
  driver_cost DECIMAL(12,2) NOT NULL,
  advance DECIMAL(12,2) NOT NULL,
  status VARCHAR(12) NOT NULL,
  created_on DATETIME NOT NULL,
  FOREIGN KEY (customer_id) REFERENCES customers(id),
  FOREIGN KEY (vehicle_id) REFERENCES vehicles(id),
  FOREIGN KEY (driver_id) REFERENCES drivers(id)
);

-- remembers that the sample data was added (the program fills it on the first run)
CREATE TABLE IF NOT EXISTS app_meta (
  k VARCHAR(40) PRIMARY KEY,
  v VARCHAR(100) NOT NULL
);
