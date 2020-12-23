class Solution:
    def isRobotBounded(self, instructions: str) -> bool:
        position = [0, 0]
        direction = "north"
        turn_left = {"north": "west", "west": "south", "south": "east", "east": "north"}
        turn_right = {"north": "east", "east": "south", "south": "west", "west": "north"}
        move = {"north": [1, 1], "east": [0, 1], "south": [1, -1], "west": [0, -1]}
        turn_count = 0
        for inst in instructions:
            if inst == "L":
                direction = turn_left[direction]
                turn_count += 1
            elif inst == "R":
                direction = turn_right[direction]
                turn_count -= 1
            else:
                axis, val = move[direction]
                position[axis] += val
        if turn_count%4 == 0:
            if position != [0, 0]:
                return False
        return True