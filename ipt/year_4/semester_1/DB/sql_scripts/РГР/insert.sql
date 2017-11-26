USE autopark
GO

INSERT INTO Driver VALUES
(N'Lyovkin Nikita Sergeevich', '1995-05-08', N'Kyiv, Ukraine', N'A', 6, 60000, N'yes'),
(N'Pupkin Ivan Ivanovich', '1994-05-08', N'Kyiv, Ukraine', N'B', 7, 6000, N'yes'),
(N'Vasilyev Ivan Petrovich', '1993-05-08', N'Kyiv, Ukraine', N'C', 10, 9000, N'yes'),
(N'Kravchuk Leonid Makarovich', '1992-05-08', N'Kyiv, Ukraine', N'C', 15, 15000, N'yes'),
(N'Kuchma Leonid Danilovich', '1991-05-08', N'Kyiv, Ukraine', N'C', 17, 16000, N'yes'),
(N'Ushenko Viktor Andreyovich', '1990-05-08', N'Kyiv, Ukraine', N'A', 2, 8000, N'yes'),
(N'Yanukovich Viktor Federovich', '1996-05-08', N'Rostov, Russia', N'A', 4, 10000, N'yes'),
(N'Poroshenko Petr Alekseyevich', '1996-05-08', N'Kyiv, Ukraine', N'A', 4, 12000, N'vacation'),
(N'Tymoshenko Uliya Volodimirovna', '1995-05-08', N'Dnepr, Ukraine', N'B', 4, 10000, N'yes'),
(N'Parubiy Andrey Vlodimirovich', '1996-05-08', N'Kyiv, Ukraine', N'D', 1, 2000, N'yes');

EXEC BusInsert N'AA0505CX', 7, N'yes';
EXEC BusInsert N'AA1111XX', 22, N'yes';
EXEC BusInsert N'AA1121TT', 100, N'yes';
EXEC BusInsert N'AA1122TT', 40, N'yes';
EXEC BusInsert N'AA1222TT', 23, N'yes';
EXEC BusInsert N'AA2222TT', 3, N'yes';
EXEC BusInsert N'AA1123TT', 2, N'yes';
EXEC BusInsert N'AA3333TT', 120, N'yes';
EXEC BusInsert N'AA4444TT', 88, N'yes';
EXEC BusInsert N'AA1010TT', 14, N'ill';

INSERT INTO WayRoute VALUES
(N'16A', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '12:15:04', '22:15:04', 10, 60),
(N'18', N'Kyiv, Ukraine', N'Kyiv, Ukraine', N'10:15:04', N'23:15:04', 20, 45),
(N'20', N'Kharkiv, Ukraine', N'Kharkiv, Ukraine', '12:15:04', '22:15:04', 30, 120),
(N'118', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '09:15:04', '20:15:04', 40, 160),
(N'55', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '07:15:04', '21:15:04', 10, 180),
(N'62', N'Odessa, Ukraine', N'Odessa, Ukraine', '06:15:04', '22:15:04', 5, 20),
(N'38', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '12:15:04', '23:15:04', 25, 50),
(N'62B', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '12:15:04', '00:15:04', 21, 100),
(N'17', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '13:15:04', '21:15:04', 5, 60),
(N'553', N'Kyiv, Ukraine', N'Kyiv, Ukraine', '15:15:04', '18:15:04', 15, 15);

INSERT INTO DriverBus VALUES (1, N'AA0505CX'),
(2, N'AA1111XX'),
(3, N'AA1121TT'),
(4, N'AA1122TT'),
(5, N'AA1222TT'),
(6, N'AA2222TT'),
(7, N'AA1123TT'),
(7, N'AA3333TT'),
(9, N'AA4444TT'),
(10, N'AA4444TT');

INSERT INTO DriverWayRoute VALUES (1, N'16A'),
(2, N'18'),
(3, N'20'),
(4, N'118'),
(5, N'55'),
(6, N'62'),
(7, N'38'),
(7, N'62B'),
(9, N'17'),
(10, N'553');