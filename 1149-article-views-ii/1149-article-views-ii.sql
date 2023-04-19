/* Write your T-SQL query statement below */
select distinct viewer_id as id 
from Views
group by viewer_id, view_date 
having COUNT(distinct article_id) > 1
order by id;

-- SELECT DISTINCT viewer_id AS id
-- FROM Views
-- GROUP BY viewer_id, view_date
-- HAVING COUNT(DISTINCT article_id) > 1
-- ORDER BY 1