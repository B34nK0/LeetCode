pub mod iterative;

pub trait Solution {
    fn matrix_reshape(nums: Vec<Vec<i32>>, r: i32, c: i32) -> Vec<Vec<i32>>;
}

#[cfg(test)]
mod tests {
    use super::Solution;

    pub fn run<S: Solution>() {
        let test_cases = [
            (
                (&[&[1, 2] as &[_], &[3, 4]] as &[&[_]], 1, 4),
                &[&[1, 2, 3, 4] as &[_]] as &[&[_]],
            ),
            ((&[&[1, 2], &[3, 4]], 2, 4), &[&[1, 2], &[3, 4]]),
        ];

        for ((nums, r, c), expected) in test_cases {
            assert_eq!(
                S::matrix_reshape(nums.iter().copied().map(<[_]>::to_vec).collect(), r, c),
                expected
            );
        }
    }
}
