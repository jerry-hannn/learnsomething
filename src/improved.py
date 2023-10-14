def max_area(height):
    max_area = 0
    left = 0
    right = len(height) - 1
    while left < right:
        max_area = max(max_area, min(height[left], height[right]) *( right - left))
        if height[left] < height[right]:
            left += 1
        elif height[left] > height[right]:
            right -= 1
        else:
            left += 1
    return max_area

    # for i in range(n):
    #     for j in range(i + 1, n):
    #         h1 = height[i]
    #         h2 = height[j]
    #         width = j - i
    #         current_area = min(h1, h2) * width
    #         max_area = max(max_area, current_area)

    # return max_area