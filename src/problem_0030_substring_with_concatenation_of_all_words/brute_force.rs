pub struct Solution;

// ------------------------------------------------------ snip ------------------------------------------------------ //

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        if words.is_empty() {
            Vec::new()
        } else {
            let word_length = words[0].len();
            let num_words = words.len();
            let window_length = word_length * num_words;
            let mut words = words;

            words.sort_unstable_by(|lhs, rhs| lhs.as_bytes().cmp(rhs.as_bytes()));

            s.as_bytes()
                .windows(window_length)
                .enumerate()
                .filter_map(move |(i, window)| {
                    let mut window_words = window.chunks(word_length).collect::<Box<_>>();

                    window_words.sort_unstable();

                    window_words
                        .iter()
                        .map(AsRef::as_ref)
                        .eq(words.iter().map(String::as_bytes))
                        .then(|| i as _)
                })
                .collect()
        }
    }
}

// ------------------------------------------------------ snip ------------------------------------------------------ //

impl super::Solution for Solution {
    fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        Self::find_substring(s, words)
    }
}

#[cfg(test)]
mod tests {
    #[test]
    fn test_solution() {
        super::super::tests::run::<super::Solution>();
    }
}
