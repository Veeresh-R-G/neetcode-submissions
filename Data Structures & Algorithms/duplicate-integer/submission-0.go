func hasDuplicate(nums []int) bool {
    
    freq := make(map[int] int)
    for _, val := range nums{
        if _, present := freq[val]; present{
            return true;
        }

        freq[val] += 1
    }

    return false;
}
