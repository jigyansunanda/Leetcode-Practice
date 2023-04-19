/* Write your T-SQL query statement below */
select 
    user_id,
    COUNT (distinct follower_id) as followers_count
from Followers
group by user_id
order by user_id;
