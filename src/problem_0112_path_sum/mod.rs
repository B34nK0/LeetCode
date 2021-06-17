use super::data_structures::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

pub mod iterative;

pub trait Solution {
    fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, sum: i32) -> bool;
}

#[cfg(test)]
mod tests {
    use super::super::test_utilities;
    use super::Solution;

    pub fn run<S: Solution>() {
        let test_cases = [
            (
                (
                    &[
                        Some(5),
                        Some(4),
                        Some(8),
                        Some(11),
                        None,
                        Some(13),
                        Some(4),
                        Some(7),
                        Some(2),
                        None,
                        None,
                        None,
                        Some(1),
                    ] as &[_],
                    22,
                ),
                true,
            ),
            ((&[], 0), false),
            ((&[Some(1), Some(2)], 1), false),
        ];

        for ((root, sum), expected) in test_cases {
            assert_eq!(
                S::has_path_sum(test_utilities::make_tree(root.iter().copied()), sum),
                expected
            );
        }
    }
}
