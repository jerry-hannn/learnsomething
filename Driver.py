import cppimport.import_hook
import PricingUtil


if __name__ == "__main__":
    print("Nice work on creating the util! Make sure to check the unit tests!")
    prevPrice = 2
    rate = 0.1
    constant = 10
    util = PricingUtil.PricingUtil()
    print(util.get_price(prevPrice, rate, constant))