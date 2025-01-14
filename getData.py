import yfinance as yf

# get the necessary data set, without volume,
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
        stock_data.to_csv('data.txt', sep='\t', header = False, index=False)


# driver code
obj = getdata()
obj.get_data()
        