use super::data_structures::TreeNode;
use std::cell::RefCell;
use std::rc::Rc;

pub mod iterative;
pub mod iterative_2;
pub mod recursive;

pub trait Solution {
    fn postorder_traversal(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<i32>;
}

#[cfg(test)]
mod tests {
    use super::super::test_utilities::make_tree;
    use super::Solution;

    pub fn run_tests<S: Solution>() {
        let test_cases = [(&[Some(1), None, Some(2), Some(3)] as &[_], &[3, 2, 1] as &[_])];

        for (serialized_tree, expected) in test_cases.iter().copied() {
            assert_eq!(
                S::postorder_traversal(make_tree(serialized_tree.iter().copied())),
                expected
            );
        }
    }
}
