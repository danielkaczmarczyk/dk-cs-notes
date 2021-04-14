// O(1) space, O(n) time
function isValidSubsequence(array, sequence) {
	let sequencePointer = 0;
	let arrayPointer = 0;
	
	while (sequencePointer < sequence.length ) {
		if (arrayPointer === array.length) return false;
		let arrayInteger = array[arrayPointer];	
		let sequenceInteger = sequence[sequencePointer];

		if (sequenceInteger === arrayInteger) {
			sequencePointer++;
		}
		arrayPointer++;
	}
	return true;
}
