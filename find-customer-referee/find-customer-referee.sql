/* Write your T-SQL query statement below */
select name from Customer where referee_id is null or referee_id != 2;