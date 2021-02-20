# Lecture 2

terminology

- database: set of named relations
- relation(table):
  - schema: description ("metadata")
  - instance: set of data satisfying the schema
- attribute (column, field)
- tuple (record, row) 

Primary keys are not limited to one column


```sql
select s.dept, avg(s.gpa), count(*)
from Students S
where S.gender = 'F'
group by S.dept
having count(*) >= 2
order by S.dept;
```

SQL DML:
General basic single-table queries

```
SELECT [DISTINCT] <column expression list>
FROM <single_table>
[WHERE <predicate>]
[GROUP BY <column list>
[HAVING <predicate>] ]
[ORDER BY <column list>]
[LIMIT <integer>];
```
