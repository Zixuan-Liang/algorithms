class Solution:
	def removeBoxes(self, boxes):

		@lru_cache(None)
		def recursion(left: int, right: int, k: int) -> int:
			if left > right:
				return 0

			while right > left and boxes[right] == boxes[right - 1]:
				right -= 1
				k += 1

			# option1: remove
			val = recursion(left, right - 1, 0) + (k + 1) * (k + 1)

			# option2 : save
			for i in range(left, right):
				if boxes[i] == boxes[right]:
					val = max(val, recursion(left, i, k + 1) + recursion(i + 1, right - 1, 0))

			return val

		return recursion(0, len(boxes) - 1, 0)