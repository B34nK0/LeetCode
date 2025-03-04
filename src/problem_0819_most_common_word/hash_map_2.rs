pub struct Solution;

// ------------------------------------------------------ snip ------------------------------------------------------ //

use std::collections::HashMap;

impl Solution {
    pub fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        let mut paragraph = paragraph;

        paragraph.make_ascii_lowercase();

        let mut counts = HashMap::new();

        for word in paragraph.split(|c: char| !matches!(c, 'a'..='z')) {
            if !word.is_empty() {
                counts.entry(word).and_modify(|count| *count += 1).or_insert(1);
            }
        }

        for word in &banned {
            counts.remove(word.as_str());
        }

        counts
            .into_iter()
            .max_by_key(|&(_, count)| count)
            .unwrap()
            .0
            .to_string()
    }
}

// ------------------------------------------------------ snip ------------------------------------------------------ //

impl super::Solution for Solution {
    fn most_common_word(paragraph: String, banned: Vec<String>) -> String {
        Self::most_common_word(paragraph, banned)
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_solution() {
        super::super::tests::run::<super::Solution>();
    }
}
