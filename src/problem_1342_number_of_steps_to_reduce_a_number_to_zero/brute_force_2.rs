pub struct Solution;

impl Solution {
    pub fn number_of_steps(mut num: i32) -> i32 {
        let mut result = -1;

        while num != 0 {
            result += 1 << (num & 1);
            num >>= 1;
        }

        result.max(0)
    }
}

impl super::Solution for Solution {
    fn number_of_steps(num: i32) -> i32 {
        Self::number_of_steps(num)
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_solution() {
        super::super::tests::run::<super::Solution>();
    }
}
