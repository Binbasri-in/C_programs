-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Keep a log of any SQL queries you execute as you solve the mystery.

-- See the reported crimes at that day
SELECT * FROM crime_scene_reports
WHERE month = 7 AND day = 28;
-- the crime happened at 10:15am at chamberlin street
-- an interview with three witnesses took place that day

-- see the transcript of each witness
SELECT * FROM interviews
WHERE month = 7 and day = 28 AND transcript LIKE "%courthouse%";
-- see the courthouse security at the parking after the crime by 10 minutes
-- at Fifer Street the thief withdraw from ATM before the crime
-- they took the earlies flight on the next day

-- list of the possible license_plate of the thief
SELECT * FROM courthouse_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit"
AND minute > 20 AND minute < 35;

-- list of the names of these license plates
SELECT * FROM people
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit"
AND minute > 20 AND minute < 35);

-- search for the person who withdraw from the ATM at fifer street
SELECT * FROM atm_transactions
WHERE atm_location = "Fifer Street" AND day = 28
AND month = 7 AND transaction_type = "withdraw";
-- list of the account numbers from that street that day

-- conect account_number to names
SELECT * FROM
bank_accounts JOIN people ON bank_accounts.person_id = people.id
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE atm_location = "Fifer Street" AND day = 28
AND month = 7 AND transaction_type = "withdraw");

-- the suspicious people who withdraw and exit from the courthouse at that time
SELECT * FROM people
WHERE name IN (
SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit"
AND minute > 20 AND minute < 35)
AND name IN (
SELECT name FROM
bank_accounts JOIN people ON bank_accounts.person_id = people.id
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE atm_location = "Fifer Street" AND day = 28
AND month = 7 AND transaction_type = "withdraw");

-- creat a table of the possible theifs
CREATE TABLE possible( name TEXT, phone_number TEXT, passport_number INTEGER);
INSERT INTO possible
SELECT name, phone_number, passport_number FROM people
WHERE name IN (
SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM courthouse_security_logs
WHERE month = 7 AND day = 28 AND hour = 10 AND activity = "exit"
AND minute > 20 AND minute < 35))
AND name IN (
SELECT name FROM
bank_accounts JOIN people ON bank_accounts.person_id = people.id
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE atm_location = "Fifer Street" AND day = 28
AND month = 7 AND transaction_type = "withdraw"));

-- The new table of possible theifs
SELECT DISTINCT * FROM possible;

-- to confirm the thief check their calls
-- the call that the theif did
SELECT * FROM phone_calls
WHERE caller IN (SELECT DISTINCT phone_number FROM possible)
AND day = 28 AND month = 7;

-- the theif information
SELECT * FROM people
WHERE phone_number IN (
SELECT caller FROM phone_calls
WHERE caller IN (SELECT DISTINCT phone_number FROM possible)
AND day = 28 AND month = 7);

-- the person who  helped him information
SELECT * FROM people
WHERE phone_number IN (
SELECT receiver FROM phone_calls
WHERE caller IN (SELECT DISTINCT phone_number FROM possible)
AND day = 28 AND month = 7);

-- where did they go
SELECT destination_airport_id,passengers.passport_number, day  FROM
airports JOIN flights ON airports.id = flights.origin_airport_id
JOIN passengers ON passengers.flight_id = flights.id
JOIN people ON people.passport_number = passengers.passport_number
WHERE passengers.passport_number IN (
SELECT passport_number FROM people
WHERE phone_number IN (
SELECT caller FROM phone_calls
WHERE caller IN (SELECT DISTINCT phone_number FROM possible)
AND day = 28 AND month = 7));

-- airport name
SELECT * FROM airports
WHERE id IN (
SELECT name  FROM possible
WHERE name = 6);