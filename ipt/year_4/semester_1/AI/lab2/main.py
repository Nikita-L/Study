from sklearn.preprocessing import LabelEncoder
import numpy as np
import pathlib
import pandas as pd
import warnings
from sklearn.cross_validation import train_test_split
from sklearn import svm
from sklearn.ensemble import RandomForestRegressor
import matplotlib.pyplot as plt
import scikitplot as skplt
from sklearn.metrics import accuracy_score
from scipy.stats import kendalltau, spearmanr
from sklearn.metrics import explained_variance_score
from sklearn.metrics import mean_absolute_error
from sklearn.metrics import median_absolute_error


warnings.filterwarnings('ignore')


# Getting data


data = pd.read_csv(
    str(pathlib.Path.cwd() / 'data' / 'raw' / 'CompleteDataset.csv'), 
    usecols=[
        'Age', 'Nationality', 'Overall', 'Club', 'Value', 'Wage', 'Special', 'Acceleration', 'Aggression',
        'Agility', 'Balance', 'Ball control', 'Composure', 'Crossing', 'Curve', 'Dribbling', 'Finishing',
        'Free kick accuracy', 'GK diving', 'GK handling', 'GK kicking', 'GK positioning', 'GK reflexes',
        'Heading accuracy', 'Interceptions', 'Jumping', 'Long passing', 'Long shots', 'Marking', 
        'Penalties', 'Positioning', 'Reactions', 'Short passing', 'Shot power', 'Sliding tackle', 
        'Sprint speed', 'Stamina', 'Standing tackle', 'Strength', 'Vision', 'Volleys', 'CAM', 'CB', 'CDM',
        'CF', 'CM', 'ID', 'LAM', 'LB', 'LCB', 'LCM', 'LDM', 'LF', 'LM', 'LS', 'LW', 'LWB', 'Preferred Positions',
        'RAM', 'RB', 'RCB', 'RCM', 'RDM', 'RF', 'RM', 'RS', 'RW', 'RWB', 'ST'
    ]
)


# Prepare data


def euro_str_to_float(row):
    try:
        return np.float64(row[1:-1])
    except:
        return np.nan

data['Value'] = data['Value'].apply(euro_str_to_float)
data['Wage'] = data['Wage'].apply(euro_str_to_float)

data = data.dropna(how='any')

le = LabelEncoder()
for col in ('Nationality', 'Club', 'Preferred Positions'):
    data[col] = le.fit_transform(data[col])

data = data.apply(pd.to_numeric, errors='coerce')
data = data.dropna(how='any')

Y = data['Overall']
X = data.drop(['Overall'], axis = 1)
feature_list = list(data.columns.values)

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2)


# Forest constructing


est = RandomForestRegressor(n_estimators=100, n_jobs=-1)  # Use all cores
est.fit(X_train, Y_train)
Y_pred = est.predict(X_test)


# Analysis

importances = est.feature_importances_
std = np.std([tree.feature_importances_ for tree in est.estimators_], axis=0)
indices = np.argsort(importances)[::-1]

print("Columns values:")
for f in range(X.shape[1]):
    print("%d) %s (%f)" % (f + 1, feature_list[f], importances[indices[f]]))

plt.figure(figsize=(18, 16))
plt.title("Columns values")
plt.bar(range(X.shape[1]), importances[indices],
       color="b", yerr=std[indices], align="center")
plt.xticks(range(X.shape[1]), feature_list, rotation='vertical')
plt.xlim([-1, X.shape[1]])


# rank correlation
print(kendalltau(Y_pred, Y_test))
print(spearmanr(Y_pred, Y_test))

# R^2, dispersion part
print('R^2 =', est.score(X_test, Y_test))

# measures the proportion to which a mathematical model accounts for the variation (dispersion)
print('EVS =', explained_variance_score(Y_test, Y_pred))

# avarage absolute error
print('MAE =', mean_absolute_error(Y_test, Y_pred))

# median absolute error
print('MedAE =', median_absolute_error(Y_test, Y_pred))
