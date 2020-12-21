class Solution():
    def one_digit(self, num):
        numbers = [i for i in range(1, 10)]
        words = ["One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"]
        table = dict(zip(numbers, words))
        return table[num]
    def teen(self, num):
        numbers = [i for i in range(10, 20)]
        words = ["Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"]
        table = dict(zip(numbers, words))
        return table[num]
    def tens(self, num):
        numbers = [i for i in range(2, 10)]
        words = ["Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"]
        table = dict(zip(numbers, words))
        return table[num]
    def three_digits(self, num):
        result = ""
        hundred = num//100
        if hundred:
            result += self.one_digit(hundred) + " Hundred"
        ten = num%100//10
        if ten == 1:
            result += (" " if result else "") + self.teen(num%100)
        else:
            if ten >= 2:
                result += (" " if result else "") + self.tens(ten)
            single = num%10
            if single:
                result += (" " if result else "") + self.one_digit(single)
        return result
    def numberToWords(self, num: int) -> str:
        ans = ""
        billion = num//1000000000
        if billion:
            ans += self.one_digit(billion) + " Billion"
        million = num%1000000000//1000000
        if million:
            ans += (" " if ans else "") + self.three_digits(million) + " Million"
        thousand = num%1000000//1000
        if thousand:
            ans += (" " if ans else "") + self.three_digits(thousand) + " Thousand"
        res = num%1000
        if res:
            ans += (" " if ans else "") + self.three_digits(res)
        if not ans:
            return "Zero"
        else:
            return ans
