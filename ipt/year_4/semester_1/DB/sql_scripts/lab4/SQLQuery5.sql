USE bookkeeping
GO

SELECT Result.subdivision name, SUM(Result.diff) res FROM
(
	SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
	JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
	JOIN Subdivisions S ON S.id = MRP.subdivision
	GROUP BY S.name, E.price, E.residualValue
) Result
GROUP BY Result.subdivision

--SELECT Result3.* FROM
--(
--			SELECT Result.subdivision name, SUM(Result.diff) res FROM
--			(
--				SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
--				JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
--				JOIN Subdivisions S ON S.id = MRP.subdivision
--				GROUP BY S.name, E.price, E.residualValue
--			) Result
--			GROUP BY Result.subdivision
--		) Result2
--JOIN 
--	(
	--SELECT Result2.name, MAX(Result2.res) maxes FROM
	--	(
	--		SELECT Result.subdivision name, SUM(Result.diff) res FROM
	--		(
	--			SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
	--			JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
	--			JOIN Subdivisions S ON S.id = MRP.subdivision
	--			GROUP BY S.name, E.price, E.residualValue
	--		) Result
	--		GROUP BY Result.subdivision
	--	) Result2
	--GROUP BY Result2.name
--	) Result3
--ON Result2.res = Result3.maxes


SELECT tt.*
FROM (
	SELECT Result.subdivision name, SUM(Result.diff) res FROM
	(
		SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
		JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
		JOIN Subdivisions S ON S.id = MRP.subdivision
		GROUP BY S.name, E.price, E.residualValue
	) Result
	GROUP BY Result.subdivision, Result res
) tt
JOIN
(
	SELECT good.name, MAX(good.res)
	FROM 
	(
		SELECT Result.subdivision name, SUM(Result.diff) res FROM
		(
			SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
			JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
			JOIN Subdivisions S ON S.id = MRP.subdivision
			GROUP BY S.name, E.price, E.residualValue
		) Result
		GROUP BY Result.subdivision
	) good
	GROUP BY good.name, good.res
) groupedtt
ON tt.name = groupedtt.name