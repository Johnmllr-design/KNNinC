import pandas as pd
import yfinance as yf
import numpy as np
import warnings
from sklearn.model_selection import train_test_split
from sklearn.neighbors import KNeighborsClassifier
from sklearn.preprocessing import StandardScaler
from sklearn.metrics import accuracy_score
from IPython.display import display
import pandas as pd

# Step  1: get the necessary data set, without volume,
# dividends, and stock splits


class getdata():
    def __init__(self) -> None:
        pass
        
    def get_data(self):
        stock_data = yf.Ticker("^GSPC")
        stock_data = stock_data.history(period="max")
        del stock_data["Volume"]
        del stock_data["Stock Splits"]
        del stock_data["Dividends"]
        del stock_data["High"]
        del stock_data["Low"]
        del stock_data["Open"]
        stock_data.dropna()
        # Print the DataFrame to a .txt file
        stock_data.to_csv('data.txt', sep='\t', index=False)

obj = getdata()
obj.get_data()
        