SELECT
    t.request_at AS Day,
    ROUND(
        SUM(CASE WHEN t.status <> 'completed' THEN 1 ELSE 0 END) / COUNT(*),
        2
    ) AS `Cancellation Rate`
FROM Trips AS t
JOIN Users AS c
    ON c.users_id = t.client_id
   AND c.banned = 'No'
JOIN Users AS d
    ON d.users_id = t.driver_id
   AND d.banned = 'No'
WHERE t.request_at BETWEEN '2013-10-01' AND '2013-10-03'
GROUP BY t.request_at;
