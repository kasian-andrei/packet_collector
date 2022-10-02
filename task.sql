-- phpMyAdmin SQL Dump
-- version 5.1.1deb5ubuntu1
-- https://www.phpmyadmin.net/
--
-- Host: localhost:3306
-- Generation Time: Oct 02, 2022 at 03:12 PM
-- Server version: 8.0.30-0ubuntu0.22.04.1
-- PHP Version: 8.0.23

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `task`
--

-- --------------------------------------------------------

--
-- Table structure for table `export_data`
--

CREATE TABLE `export_data` (
  `id` int UNSIGNED NOT NULL,
  `group_id` int UNSIGNED DEFAULT NULL,
  `received_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `data_length` int UNSIGNED NOT NULL,
  `source_address` varchar(255) NOT NULL,
  `destination_address` varchar(255) NOT NULL,
  `source_port` int UNSIGNED NOT NULL,
  `destination_port` int UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `export_data`
--

INSERT INTO `export_data` (`id`, `group_id`, `received_time`, `data_length`, `source_address`, `destination_address`, `source_port`, `destination_port`) VALUES
(1, 1, '2022-10-02 15:02:45', 5, '127.0.0.1', '127.0.0.1', 49100, 50500),
(2, 1, '2022-10-02 15:02:45', 18, '127.0.0.1', '127.0.0.1', 49100, 50500),
(3, 1, '2022-10-02 15:02:45', 9, '127.0.0.1', '127.0.0.1', 49100, 50500),
(4, 3, '2022-10-02 15:03:45', 13, '127.0.0.1', '127.0.0.1', 49100, 50500),
(5, 3, '2022-10-02 15:03:45', 7, '127.0.0.1', '127.0.0.1', 49100, 50500),
(6, 3, '2022-10-02 15:03:45', 3, '127.0.0.1', '127.0.0.1', 49100, 50500),
(7, 3, '2022-10-02 15:03:45', 6, '127.0.0.1', '127.0.0.1', 49100, 50500);

-- --------------------------------------------------------

--
-- Table structure for table `export_group`
--

CREATE TABLE `export_group` (
  `id` int UNSIGNED NOT NULL,
  `export_time` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `total_packets` int UNSIGNED NOT NULL,
  `total_bytes` int UNSIGNED NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

--
-- Dumping data for table `export_group`
--

INSERT INTO `export_group` (`id`, `export_time`, `total_packets`, `total_bytes`) VALUES
(1, '2022-10-02 15:02:45', 3, 96),
(2, '2022-10-02 15:03:15', 0, 0),
(3, '2022-10-02 15:03:45', 4, 128);

--
-- Indexes for dumped tables
--

--
-- Indexes for table `export_data`
--
ALTER TABLE `export_data`
  ADD PRIMARY KEY (`id`);

--
-- Indexes for table `export_group`
--
ALTER TABLE `export_group`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `export_data`
--
ALTER TABLE `export_data`
  MODIFY `id` int UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=8;

--
-- AUTO_INCREMENT for table `export_group`
--
ALTER TABLE `export_group`
  MODIFY `id` int UNSIGNED NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=4;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
