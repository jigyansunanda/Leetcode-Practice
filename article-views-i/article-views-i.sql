/* Write your T-SQL query statement below */
SELECT DISTINCT author_id AS id from Views
WHERE author_id = viewer_id
order by id;

-- SELECT DISTINCT author_id AS id FROM Views 
-- where author_id = viewer_id 
-- ORDER BY id