public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> map = new();
        int firstNumber, secondNumber;

        for(int i = 0; i < nums.Length; i++){
            firstNumber = nums[i]; 
            secondNumber = target - firstNumber; 
            if(kutu.TryGetValue(secondNumber, out int index)){
                return new int[]{i, index};
            }

            map[firstNumber] = i;
        }
        return new int[]{};
    }
}