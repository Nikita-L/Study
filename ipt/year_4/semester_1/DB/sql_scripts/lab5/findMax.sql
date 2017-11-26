USE bookkeeping
GO

--Subdivision with max equipment price and residual price difference

SELECT Result2.name, Result2.res FROM
(
	SELECT Result.subdivision name, SUM(Result.diff) res FROM
	(
		SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
		JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
		JOIN Subdivisions S ON S.id = MRP.subdivision
		GROUP BY S.name, E.price, E.residualValue
	) Result
	GROUP BY Result.subdivision
) Result2
JOIN
(
SELECT MAX(res) resMax FROM
	(
		SELECT Result.subdivision name, SUM(Result.diff) res FROM
		(
			SELECT S.name subdivision, E.price - E.residualValue diff FROM Equipment E
			JOIN MaterialResponsiblePeople MRP ON MRP.id = E.materialResponsiblePerson
			JOIN Subdivisions S ON S.id = MRP.subdivision
			GROUP BY S.name, E.price, E.residualValue
		) Result
		GROUP BY Result.subdivision
	) Total
) Total2
ON Result2.res = Total2.resMax
GROUP BY Result2.name, Result2.res
--JOIN Subdivisions S ON S.id = MRP.subdivision