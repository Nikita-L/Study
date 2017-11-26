USE bookkeeping
GO

INSERT INTO SubdivisionTypes VALUES (N'Managment'),
									(N'Development'),
									(N'Researching'),
									(N'Non-profit activity'),
									(N'Governmental cooperation'),
									(N'Jurisprudence'),
									(N'Maintaining'),
									(N'Testers'),
									(N'Designers'),
									(N'Finance');
INSERT INTO Subdivisions VALUES (N'General Managment', 32),
								(N'Bookkeeping', 32),
								(N'Human Resources Managment', 32),
								(N'Python Development', 33),
								(N'Java Development', 33),
								(N'Blockchain Researching', 34),
								(N'Machine Learning Researching', 34),
								(N'Databases Testers', 39),
								(N'Interface Design', 40),
								(N'UI/UX', 40);
INSERT INTO MaterialResponsiblePeople VALUES (N'Petrov Ivan Nikolaevich', 6),
											 (N'Sidorov Andrey Ivanovich', 6),
											 (N'Solovyev Andrey Ginadiyevich', 7),
											 (N'Lyovkin Nikita Sergeyevich', 8),
											 (N'Potapenko Aleksey Nikolaevich', 9),
											 (N'Kondratuk Ivan Vlodimirovich', 9),
											 (N'Pushkin Alexandr Sergeyevich', 10),
											 (N'Tolstoy Lev Nikolayevich', 11),
											 (N'Shevchenko Taras Grigoriyevich', 12),
											 (N'Petrenko Vasiliyi Petrovich', 13);
INSERT INTO Equipment VALUES (N'Desktop 12', 2000, 1800, 6),
							 (N'Desktop 13', 1500, 1400, 6),
							 (N'Notebook', 1000, 800, 7),
							 (N'iPhone X', 1000, 800, 6),
							 (N'MacBook Air', 2000, 1750, 8),
							 (N'MacBook Pro', 4500, 4400, 8),
							 (N'Asus ZenBook 1', 900, 850, 10),
							 (N'Asus ZenBook 2', 900, 850, 11),
							 (N'Asus ZenBook 3', 900, 850, 12),
							 (N'Asus ZenBook 4', 900, 850, 13);