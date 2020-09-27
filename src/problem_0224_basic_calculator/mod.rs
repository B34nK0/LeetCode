pub mod recursive_descent;
pub mod stack;

pub trait Solution {
    fn calculate(s: String) -> i32;
}

#[cfg(test)]
mod tests {
    use super::Solution;

    pub fn run<S: Solution>() {
        let test_cases = [("1 + 1", 2), (" 2-1 + 2 ", 3), ("(1+(4+5+2)-3)+(6+8)", 23)];

        for (s, expected) in test_cases.iter().copied() {
            assert_eq!(S::calculate(s.to_string()), expected);
        }
    }
}
