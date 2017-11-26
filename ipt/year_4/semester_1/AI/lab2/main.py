from imdb import IMDb


ia = IMDb()
the_matrix = ia.get_movie('0133093')
print(dir(the_matrix))
print(the_matrix.summary())
print(the_matrix['rating'])
