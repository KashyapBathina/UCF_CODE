package project1;

public class TwoFourTree {
    private class TwoFourTreeItem {
        int values = 1;
        int value1 = 0;                             // always exists.
        int value2 = 0;                             // exists iff the node is a 3-node or 4-node.
        int value3 = 0;                             // exists iff the node is a 4-node.
        boolean isLeaf = true;
        
        TwoFourTreeItem parent = null;              // parent exists iff the node is not root.
        TwoFourTreeItem leftChild = null;           // left and right child exist iff the note is a non-leaf.
        TwoFourTreeItem rightChild = null;          
        TwoFourTreeItem centerChild = null;         // center child exists iff the node is a non-leaf 3-node.
        TwoFourTreeItem centerLeftChild = null;     // center-left and center-right children exist iff the node is a non-leaf 4-node.
        TwoFourTreeItem centerRightChild = null;

        public boolean isTwoNode() {
            return values==1;
        }

        public boolean isThreeNode() {
        	return values==2;
        }

        public boolean isFourNode() {
        	return values==3;
        }

        public boolean isRoot() {
            return parent==null;
        }

        public TwoFourTreeItem(int value1) {
        	this.value1 = value1;
        	values = 1;
        }

        public TwoFourTreeItem(int value1, int value2) {
        	this.value1 = value1;
        	this.value2 = value2;
        	values = 2;
        }

        public TwoFourTreeItem(int value1, int value2, int value3) {
        	this.value1 = value1;
        	this.value2 = value2;
        	this.value3 = value3;
        	values = 3;
        }

        private void printIndents(int indent) {
            for(int i = 0; i < indent; i++) System.out.printf("  ");
        }

        public void printInOrder(int indent) {
            if(!isLeaf) leftChild.printInOrder(indent + 1);
            printIndents(indent);
            System.out.printf("%d\n", value1);
            if(isThreeNode()) {
                if(!isLeaf) centerChild.printInOrder(indent + 1);
                printIndents(indent);
                System.out.printf("%d\n", value2);
            } else if(isFourNode()) {
                if(!isLeaf) centerLeftChild.printInOrder(indent + 1);
                printIndents(indent);
                System.out.printf("%d\n", value2);
                if(!isLeaf) centerRightChild.printInOrder(indent + 1);
                printIndents(indent);
                System.out.printf("%d\n", value3);
            }
            if(!isLeaf) rightChild.printInOrder(indent + 1);
        }
    }

    TwoFourTreeItem root = null;

    
    /*--------------------------------------------------------------------------------------------------------------*/

    
    public boolean addValue(int value) {
        if (root == null) {
            root = new TwoFourTreeItem(value);
            return true;
        }
        return insertRecursive(root, value);
    }

    private boolean insertRecursive(TwoFourTreeItem node, int value) {
    	// Split tree to maintain 
        if (node.isFourNode()) {
            node = splitNode(node);
        }
        
        // If the node is a leaf, insert the value directly
        if (node.isLeaf) {
            return insertIntoLeaf(node, value);
        }

        // Recursively traverse to find the correct leaf
        if (value < node.value1) {
            if (node.leftChild == null) {
                node.leftChild = new TwoFourTreeItem(value);
                node.leftChild.parent = node;
                node.isLeaf = false; // Update isLeaf
                return true;
            } else {
                return insertRecursive(node.leftChild, value);
            }
        } else if (node.isThreeNode() && value < node.value2) {
            if (node.centerChild == null) {
                node.centerChild = new TwoFourTreeItem(value);
                node.centerChild.parent = node;
                node.isLeaf = false; // Update isLeaf
                return true;
            } else {
                return insertRecursive(node.centerChild, value);
            }
        } else if (node.isFourNode() && value < node.value2) {
        	if (node.centerLeftChild == null) {
        		node.centerLeftChild = new TwoFourTreeItem(value);
                node.centerLeftChild.parent = node;
                node.isLeaf = false; // Update isLeaf
                return true;
        	}
        	else {
        		return insertRecursive(node.centerLeftChild, value);
        	}
        } else if (node.isFourNode() && value > node.value2 && value < node.value3) {
        	if (node.centerRightChild == null) {
        		node.centerRightChild = new TwoFourTreeItem(value);
                node.centerRightChild.parent = node;
                node.isLeaf = false; // Update isLeaf
                return true;
        	}
        	else {
        		return insertRecursive(node.centerRightChild, value);
        	}
        } else {
            if (node.rightChild == null) {
                node.rightChild = new TwoFourTreeItem(value);
                node.rightChild.parent = node;
                node.isLeaf = false; // Update isLeaf
                return true;
            } else {
                return insertRecursive(node.rightChild, value);
            }
        }
    }

    private TwoFourTreeItem splitNode(TwoFourTreeItem node) {
        TwoFourTreeItem parent = node.parent;

        // Split node into two 2-nodes and move middle value up to the parent
        TwoFourTreeItem left = new TwoFourTreeItem(node.value1);
        TwoFourTreeItem right = new TwoFourTreeItem(node.value3);


        if (!node.isLeaf) {
            left.leftChild = node.leftChild;
            left.rightChild = node.centerLeftChild;
            right.leftChild = node.centerRightChild;
            right.rightChild = node.rightChild;

            // Set the correct parent pointers for children
            if (left.leftChild != null) {
            	left.leftChild.parent = left;
            	left.isLeaf = false;
            }
            if (left.rightChild != null) {
            	left.rightChild.parent = left;
            	left.isLeaf = false;
            }
            if (right.leftChild != null) {
            	right.leftChild.parent = right;
            	right.isLeaf = false;
            }
            if (right.rightChild != null) {
            	right.rightChild.parent = right;
            	right.isLeaf = false;
            }
        }

        if (parent == null) {
            // If the node is root, create a new root
            root = new TwoFourTreeItem(node.value2);
            root.leftChild = left;
            root.rightChild = right;
            left.parent = root;
            right.parent = root;
            parent = root;
            root.isLeaf=false;
        } else {
            insertValueIntoParent(parent, node.value2, left, right);
            parent.isLeaf = false;
        }
        
        return parent;
    }
    
    private void insertValueIntoParent(TwoFourTreeItem parent, int value, TwoFourTreeItem left, TwoFourTreeItem right) {
        // Inserts the value and updates the parent's children pointers
    	if (parent.isTwoNode()) {
    		if (value < parent.value1) {
    			parent.value2 = parent.value1;
    			parent.value1 = value;
    			parent.centerChild = left;
                parent.rightChild = right;
    		}
    		else {
    			parent.value2 = value;
    			parent.centerChild = left;
                parent.rightChild = right;
    		}
    		parent.values = 2;
    	}
    	else {
    		if (value < parent.value1) {
    			parent.value3 = parent.value2;
                parent.value2 = parent.value1;
                parent.value1 = value;
                parent.centerLeftChild = parent.centerChild;
                parent.centerRightChild = left;
                parent.rightChild = right;
    		}
    		else if (value > parent.value1 && value < parent.value2) {
    			parent.value3 = parent.value2;
                parent.value2 = value;
                parent.centerLeftChild = parent.centerChild;
                parent.centerRightChild = left;
                parent.rightChild = right;
    		}
    		else {
    			parent.value3 = value;
    			parent.centerLeftChild = parent.centerChild;
                parent.centerRightChild = left;
                parent.rightChild = right;
    		}
    		parent.values = 3;
    	}
    	left.parent = parent;
        right.parent = parent;
    	return;
    }


    private boolean insertIntoLeaf(TwoFourTreeItem node, int value) {
        // Insert into a 2-node or 3-node leaf
        if (node.isTwoNode()) {
            if (value < node.value1) {
                node.value2 = node.value1;
                node.value1 = value;
            } 
            else {
                node.value2 = value;
            }
            node.values = 2;
            return true;
        } 
        else if (node.isThreeNode()) {
            if (value < node.value1) {
                node.value3 = node.value2;
                node.value2 = node.value1;
                node.value1 = value;
            } 
            else if (value < node.value2) {
                node.value3 = node.value2;
                node.value2 = value;
            } 
            else {
                node.value3 = value;
            }
            node.values = 3;
            return true;
        }
        return false;
    }

    
    
    /*--------------------------------------------------------------------------------------------------------------*/
    
    
    public boolean hasValue(int value) {
    	return searchRecursive(root, value);
    }

    private boolean searchRecursive(TwoFourTreeItem node, int value) {
        if (node == null) return false;

        if (value == node.value1 ||  value == node.value2 || value == node.value3) {
            return true;
        }

        if (value < node.value1) {
            return searchRecursive(node.leftChild, value);
        } else if (node.isThreeNode() && (value < node.value2)) {
            return searchRecursive(node.centerChild, value);
        } else if (node.isFourNode() && (value < node.value2)) {
            return searchRecursive(node.centerLeftChild, value);
        } else if (node.isFourNode() && (value < node.value3)) {
            return searchRecursive(node.centerRightChild, value);
        } else {
            return searchRecursive(node.rightChild, value);
        }
    }

    /*--------------------------------------------------------------------------------------------------------------*/
    

    // Updated deleteValue method, using getPredecessor and getSuccessor
    public boolean deleteValue(int value) {
        if (root == null) return false; // Tree is empty
        else if (!hasValue(value)) return false; // Tree doesn't have value
        else return deleteRecursive(root, value);
    }

    private boolean deleteRecursive(TwoFourTreeItem node, int value) {
    	// handle merging of root if both root and children are two nodes
    	if (node.isRoot() && node.isTwoNode() && node.leftChild.isTwoNode() && node.rightChild.isTwoNode()) {
    		TwoFourTreeItem left = node.leftChild;
    		TwoFourTreeItem right = node.rightChild;

    		TwoFourTreeItem merged = new TwoFourTreeItem(left.value1, node.value1, right.value1);
    		if (!left.isLeaf) {
	    		merged.leftChild = left.leftChild;
	            merged.centerLeftChild = left.rightChild;
	    		merged.centerRightChild = right.leftChild;
	            merged.rightChild = right.rightChild;
	            
	            // Set the correct parent pointers for children
	            merged.leftChild.parent = merged;
	            merged.centerLeftChild.parent = merged;
	            merged.centerRightChild.parent = merged;
	            merged.rightChild.parent = merged;
	            merged.isLeaf = false;
    		}
    		

            root = merged;
            return deleteRecursive(merged, value); 
    	}
    	// else if two node, need to rotate or merge
    	else if (node.isTwoNode() && !node.isRoot()) {
    		// if sibling is 3 or four node
    		TwoFourTreeItem sibling = siblingThreeOrFourNode(node);
			if (sibling != null) {
				node = rotateTree(node, sibling); // rotate
				return deleteRecursive(node, value); 
    		}
    		// else no three of four node sibling
    		else {
    			node = fuseTree(node); // fuse with parent and sibling
				return deleteRecursive(node, value); 
    		}
    	}
    	// else if not two node, can just iterate and recurse deeper into tree
    	else {    	
    		// if value to be deleted in current node, call delete
    		if (value==node.value1 || value==node.value2 || value==node.value3) {
    			return deleteNode(node, value);
    		}
            // else Recursively traverse to find the correct leaf
    		else {
	            if (value <= node.value1) {
	                return deleteRecursive(node.leftChild, value);
	            } else if (node.isThreeNode() && value >= node.value1 && value <= node.value2) {
	                return deleteRecursive(node.centerChild, value);
	            } else if (node.isFourNode() && value >= node.value1 && value <= node.value2) {
	            	return deleteRecursive(node.centerLeftChild, value);
	            } else if (node.isFourNode() && value <= node.value3) {
	            	return deleteRecursive(node.centerRightChild, value);
	            } else {
	                return deleteRecursive(node.rightChild, value);
	            }
    		}
    	}    
    }
    
    
    public boolean deleteNode(TwoFourTreeItem node, int value) {
		// if leaf, delete
    	if (node.isLeaf) {
    	    if (value == node.value1) {
    	        node.value1 = node.value2;
    	        node.value2 = node.value3;
    	        node.values--;
    	    } else if (value == node.value2) {
    	        node.value2 = node.value3;
    	        node.values--;
    	    } else {
    	    	node.values--;
    	    }
    	    return true;
    	} 
		// else if internal, delete and replace with in order successor
    	else {
            TwoFourTreeItem successor = null;
            if (value == node.value1) {
                // Find successor for value1
            	successor = getSuccessor(node, 1);
                int successorValue = successor.value1;
                deleteRecursive(node, successor.value1); // delete that successor
                node.value1 = successorValue; // Replace node's value with successor's value
                return true;
            } else if (value == node.value2) {
                // Find successor for value2
            	successor = getSuccessor(node, 2);
                int successorValue = successor.value1;
                deleteRecursive(node, successor.value1);
                node.value2 = successorValue; 
                return true;
            } else {
                // Find successor for value3
            	successor = getSuccessor(node, 3);
                int successorValue = successor.value1;
                deleteRecursive(node, successor.value1);
                node.value3 = successorValue;
                return true;
            }

        }
    }
    
    public TwoFourTreeItem rotateTree(TwoFourTreeItem node, TwoFourTreeItem sibling) {
        TwoFourTreeItem parent = node.parent;
                
        // rotate with parent two nodes
        if (parent.isTwoNode()) {
        	// if node on left and sibling right
        	if (node==parent.leftChild && sibling==parent.rightChild) {
        		node = leftNodeRotate(node,sibling);
        		return node;
        	}
        	//if node on right and sibling left
        	else {
        		node = rightNodeRotate(node,sibling);
        		return node;
        	}
        }
        
        // rotate with parent three nodes
        else if (parent.isThreeNode()) {
        	// if node on left and sibling center
        	if (node==parent.leftChild && sibling==parent.centerChild) {
        		node = leftNodeRotate(node,sibling);
        		return node;
        	}
        	// if node on center and sibling left
        	else if (node==parent.centerChild && sibling==parent.leftChild) {
        		node = rightNodeRotate(node,sibling);
        		return node;
        	}
        	// if node on center and sibling right
        	else if (node==parent.centerChild && sibling==parent.rightChild) {
        		node = leftNodeRotate(node,sibling);
        		return node;
        	}
        	// if node on right and sibling center
        	else {
        		node = rightNodeRotate(node,sibling);
        		return node;
        	}
        }
        
        // rotate with parent four nodes
        else {
        	// if node on left and sibling center left
        	if (node==parent.leftChild && sibling==parent.centerLeftChild) {
        		node = leftNodeRotate(node,sibling);
        		return node;
        	}        	
        	// if node on center left and sibling left
        	else if (node==parent.centerLeftChild && sibling==parent.leftChild) {
        		node = rightNodeRotate(node,sibling);
        		return node;
        	}        	
        	// if node on center left and sibling center right
        	else if (node==parent.centerLeftChild && sibling==parent.centerRightChild) {
        		node = leftNodeRotate(node,sibling);
        		return node;
        	}
        	// if node on center right and sibling center left
        	else if (node==parent.centerRightChild && sibling==parent.centerLeftChild) {
        		node = rightNodeRotate(node,sibling);
        		return node;
        	}
        	// if node on center right and sibling right
        	else if (node==parent.centerRightChild && sibling==parent.rightChild) {
        		node = leftNodeRotate(node,sibling);
        		return node;
        	}
        	// if node on right and sibling center right
        	else {
        		node = rightNodeRotate(node,sibling);
        		return node;
        	}
        }        
    }
    
    public TwoFourTreeItem leftNodeRotate(TwoFourTreeItem node, TwoFourTreeItem sibling) {
    	// bring parent down and changing parent
    	TwoFourTreeItem parent = node.parent;
		node.values = 2;
    	if (parent.isTwoNode()) {
    		node.value2 = parent.value1;
    		parent.value1 = sibling.value1;
    	}
    	else if (parent.isThreeNode()) {
    		if (node==parent.leftChild) {
    			node.value2 = parent.value1; 
    			parent.value1 = sibling.value1;
    		}
    		else {
    			node.value2 = parent.value2; 
    			parent.value2 = sibling.value1;
    		}
    	}
    	else {
    		if (node==parent.leftChild) {
    			node.value2 = parent.value1; 
    			parent.value1 = sibling.value1;
    		}
    		else if (node==parent.centerLeftChild) {
    			node.value2 = parent.value2; 
    			parent.value2 = sibling.value1;
    		}
    		else {
    			node.value2 = parent.value3; 
    			parent.value3 = sibling.value1;
    		}
    	}
    			
		// change sibling values
		if (sibling.isThreeNode()) { 
			sibling.value1 = sibling.value2;
		}
		else {
			sibling.value1 = sibling.value2;
			sibling.value2 = sibling.value3;
		}
		
		// attach sibling's children
		node.centerChild = node.rightChild;
		node.rightChild = null;
		if (!sibling.isLeaf) {
			node.rightChild = sibling.leftChild;
			node.rightChild.parent = node;
			
			// de-attach sibling's children
			if (sibling.isThreeNode()) {
				sibling.leftChild = sibling.centerChild;
				sibling.centerChild = null;
			}
			else {
				sibling.leftChild = sibling.centerLeftChild;
				sibling.centerChild = sibling.centerRightChild;
				sibling.centerLeftChild = null;
				sibling.centerRightChild = null;
			}
		}
		
		
		sibling.values--;
		return node;
    }
    
    public TwoFourTreeItem rightNodeRotate(TwoFourTreeItem node, TwoFourTreeItem sibling) {
    	TwoFourTreeItem parent = node.parent;
		node.value2 = node.value1;
    	node.values = 2;
		if (parent.isTwoNode()) {
			node.value1 = parent.value1; // bring parent down
			if (sibling.isThreeNode()) parent.value1 = sibling.value2;
			else parent.value1 = sibling.value3;
    	}
    	else if (parent.isThreeNode()) {
    		if (node==parent.centerChild) {
    			node.value1 = parent.value1; // bring parent down
    			if (sibling.isThreeNode()) parent.value1 = sibling.value2;
    			else parent.value1 = sibling.value3;
    		}
    		else {
    			node.value1 = parent.value2; // bring parent down
    			if (sibling.isThreeNode()) parent.value2 = sibling.value2;
    			else parent.value2 = sibling.value3;
    		}
    	}
    	else {
    		if (node==parent.centerLeftChild) {
    			node.value1 = parent.value1; // bring parent down
    			if (sibling.isThreeNode()) parent.value1 = sibling.value2;
    			else parent.value1 = sibling.value3;
    		}
    		else if (node==parent.centerRightChild) {
    			node.value1 = parent.value2; // bring parent down
    			if (sibling.isThreeNode()) parent.value2 = sibling.value2;
    			else parent.value2 = sibling.value3;
    		}
    		else {
    			node.value1 = parent.value3; // bring parent down
    			if (sibling.isThreeNode()) parent.value3 = sibling.value2;
    			else parent.value3 = sibling.value3;
    		}
    	}
		
		// change sibling values
		if (sibling.isThreeNode()) { 
			sibling.value1 = sibling.value2;
		}
		else {
			sibling.value1 = sibling.value2;
			sibling.value2 = sibling.value3;
		}
		
		// attach sibling's children
		node.rightChild = node.centerChild;
		node.centerChild = node.leftChild;
		node.leftChild = null;
		if (!sibling.isLeaf) {
			node.leftChild = sibling.rightChild;
			node.leftChild.parent = node;
			
			// de-attach sibling's children
			if (sibling.isThreeNode()) {
				sibling.rightChild = sibling.centerChild;
				sibling.centerChild = null;
			}
			else {
				sibling.centerChild = sibling.centerLeftChild;
				sibling.rightChild = sibling.centerRightChild;
				sibling.centerLeftChild = null;
				sibling.centerRightChild = null;
			}
		}
		

		sibling.values--;
		return node;
    }
    
    public TwoFourTreeItem fuseTree(TwoFourTreeItem node) {
        TwoFourTreeItem parent = node.parent;
        
        // if parent three node
        if (parent.isThreeNode()) {
        	// if node in left or center
        	if (node==parent.leftChild || node==parent.centerChild) {
        		// adding values to merged
        		node = parent.leftChild;
        		TwoFourTreeItem sibling = parent.centerChild;
        		node.value2 = parent.value1;
        		node.value3 = sibling.value1;
        		node.values = 3;
        		
        		// merging children
        		if (!node.isLeaf || !sibling.isLeaf) {
	        		node.centerLeftChild = node.rightChild;
	        		node.centerRightChild = sibling.leftChild;
	        		node.rightChild = sibling.rightChild;
	        		node.centerRightChild.parent = node;
	        		node.rightChild.parent = node;
        		}
        		
        		// removing value from parent
        		parent.value1 = parent.value2;
        		parent.values--;
        		parent.centerChild = null;
        		node.parent = parent;
        		return node;
        	}
        	// if node in right
        	else {
        		// adding values to merged
        		node = parent.centerChild;
        		TwoFourTreeItem sibling = parent.rightChild;
        		node.value2 = parent.value2;
        		node.value3 = sibling.value1;
        		node.values = 3;
        		
        		// merging children
        		if (!node.isLeaf || !sibling.isLeaf) {
	        		node.centerLeftChild = node.rightChild;
	        		node.centerRightChild = sibling.leftChild;
	        		node.rightChild = sibling.rightChild;
	        		node.centerRightChild.parent = node;
	        		node.rightChild.parent = node;
        		}
        		

        		
        		// removing value from parent
        		parent.values--;
        		parent.rightChild = node;
        		parent.centerChild = null;
        		node.parent = parent;
        		return node;
        	}
        }
        // if parent four node
        else {
        	// if node right child or center left child
        	if (node==parent.leftChild || node==parent.centerLeftChild) {
        		// adding values to merged
        		node = parent.leftChild;
        		TwoFourTreeItem sibling = parent.centerLeftChild;
        		node.value2 = parent.value1;
        		node.value3 = sibling.value1;
        		node.values = 3;
        		
        		// merging children
        		if (!node.isLeaf || !sibling.isLeaf) {
	        		node.centerLeftChild = node.rightChild;
	        		node.centerRightChild = sibling.leftChild;
	        		node.rightChild = sibling.rightChild;
	        		node.centerRightChild.parent = node;
	        		node.rightChild.parent = node;
        		}
	        		
        		// removing value from parent
        		parent.value1 = parent.value2;
        		parent.value2 = parent.value3;
        		parent.values--;
        		parent.leftChild = node;
        		parent.centerChild = parent.centerRightChild;
        		parent.centerLeftChild = null;
        		parent.centerRightChild = null;
        		node.parent = parent;
        		return node;
        	}
        	// if node center right child
        	else if (node==parent.centerRightChild) {
        		// adding values to merged
        		node = parent.centerLeftChild;
        		TwoFourTreeItem sibling = parent.centerRightChild;
        		node.value2 = parent.value2;
        		node.value3 = sibling.value1;
        		node.values = 3;
        		
        		// merging children
        		if (!node.isLeaf || !sibling.isLeaf) {
	        		node.centerLeftChild = node.rightChild;
	        		node.centerRightChild = sibling.leftChild;
	        		node.rightChild = sibling.rightChild;
	        		node.centerRightChild.parent = node;
	        		node.rightChild.parent = node;
        		}
        		
	        		
        		// removing value from parent
        		parent.value2 = parent.value3;
        		parent.values--;
        		parent.centerChild = node;
        		parent.centerLeftChild = null;
        		parent.centerRightChild = null;
        		node.parent = parent;
        		return node;
        	}
        	// if node right child
        	else {
        		// adding values to merged
        		node = parent.centerRightChild;
        		TwoFourTreeItem sibling = parent.rightChild;
        		node.value2 = parent.value3;
        		node.value3 = sibling.value1;
        		node.values = 3;
        		
        		// merging children
        		if (!node.isLeaf || !sibling.isLeaf) {
	        		node.centerLeftChild = node.rightChild;
	        		node.centerRightChild = sibling.leftChild;
	        		node.rightChild = sibling.rightChild;
	        		node.centerRightChild.parent = node;
	        		node.rightChild.parent = node;
        		}
        		
        		
        		// removing value from parent
        		parent.values--;
        		parent.centerChild = parent.centerLeftChild;
        		parent.rightChild = node;
        		parent.centerLeftChild = null;
        		parent.centerRightChild = null;
        		node.parent = parent;
        		return node;
        	}
        }
    }
    
    
	private TwoFourTreeItem getSuccessor(TwoFourTreeItem node, int valuePos) {
        // Find successor, min on the right by going right once, then left (leftmost right descendant)
		//if (node==null) System.out.println("ASJKDHAJSBDJABHSKDJABSDJASBDJ");
        TwoFourTreeItem current = null;
        
        // Traverse and find rightmost node
        if (valuePos == 1) {
        	if (node.isTwoNode()) {
        		current = node.rightChild;
        	}
        	else if (node.isThreeNode()) {
        		current = node.centerChild;
        	}
        	else {
        		current = node.centerLeftChild;
        	}
        } else if (valuePos == 2) {
        	if (node.isThreeNode()) {
        		current = node.rightChild;
        	}
        	else {
        		current = node.centerRightChild;
        	} 
        } else {
        	current = node.rightChild;
        }
        
        // Keep going to the leftmost child to find the successor
        while (!current.isLeaf) {
            current = current.leftChild;
        }
        return current;
    }

    
    
    public TwoFourTreeItem siblingThreeOrFourNode(TwoFourTreeItem node) {
    	TwoFourTreeItem parent = node.parent;
        
        // if two node
        if (parent.isTwoNode()) {
        	// if left, check right
        	if (parent.leftChild==node && (parent.rightChild.isThreeNode() || parent.rightChild.isFourNode())) {
        		return parent.rightChild;
        	}
        	// if right, check left
        	if (parent.rightChild==node && (parent.leftChild.isThreeNode() || parent.leftChild.isFourNode())) {
        		return parent.leftChild;
        	}
        }
        // if three node
        else if (parent.isThreeNode()) {
        	// if left, check center
        	if (parent.leftChild==node && (parent.centerChild.isThreeNode() || parent.centerChild.isFourNode())) {
        		return parent.centerChild;
        	}
        	// if center, check left and right
        	if (parent.centerChild==node) {
        		if (parent.leftChild.isThreeNode() || parent.leftChild.isFourNode()) return parent.leftChild;
        		if (parent.rightChild.isThreeNode() || parent.rightChild.isFourNode()) return parent.rightChild;
        	}
        	// if right, check center
        	if (parent.rightChild==node && (parent.centerChild.isThreeNode() || parent.centerChild.isFourNode())) {
        		return parent.centerChild;
        	}
        }
        // if four node
        else {
        	// if left, check center left
        	if (parent.leftChild==node && (parent.centerLeftChild.isThreeNode() || parent.centerLeftChild.isFourNode())) {
        		return parent.centerLeftChild;
        	}
        	// if center left, check left and center right
        	if (parent.centerLeftChild==node) {
        		if (parent.leftChild.isThreeNode() || parent.leftChild.isFourNode()) return parent.leftChild;
        		if (parent.centerRightChild.isThreeNode() || parent.centerRightChild.isFourNode()) return parent.centerRightChild;
        	}
        	// if center right, check center left and right
        	if (parent.centerRightChild==node) {
        		if (parent.centerLeftChild.isThreeNode() || parent.centerLeftChild.isFourNode()) return parent.centerLeftChild;
        		if (parent.rightChild.isThreeNode() || parent.rightChild.isFourNode()) return parent.rightChild;
        	}
        	// if right, check center right
        	if (parent.rightChild==node && (parent.centerRightChild.isThreeNode() || parent.centerRightChild.isFourNode())) {
        		return parent.centerRightChild;
        	}
        }
    	return null;
    }
    
    /*--------------------------------------------------------------------------------------------------------------*/
    
    public void printInOrder() {
        if(root != null) root.printInOrder(0);
    }

    public TwoFourTree() {
    	
    }
}
